// 采用自底向上的分析方法
%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
}

%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

// 属性值可能的取值类型
%union {
    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
}

// 终结符的属性类型，对于 IF、ELSE 等保留字，由于语义动作中用不到，则不设置属性(默认为int 型)

%token <strtype> ID 
%token <itype> INTEGER
// 分支、循环、跳转保留字
%token IF ELSE WHILE RETURN BREAK CONTINUE
%token INT VOID 
// 标点
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON LBRACKET RBRACKET COMMA   
// 算术符
%token ADD SUB MUL DIV MOD 
// 逻辑运算符、比较符
%token OR AND LESS LESSEQUAL GREATER GREATEREQUAL ASSIGN EQUAL NOTEQUAL NOT
%token CONST


// 开始符号
%start Program

// 指定每个非终结符节点的属性类型
%nterm <stmttype> Stmts Stmt
%nterm <stmttype> AssignStmt BlockStmt 
%nterm <stmttype> IfStmt WhileStmt BreakStmt ContinueStmt ReturnStmt 
%nterm <stmttype> DeclStmt FuncDef EmptyStmt FuncDefParams FuncDefParam VarDefs ConstDefs VarDef ConstDef ExprStmt MaybeFuncDefParams
%nterm <exprtype> Exp AddExp MulExp UnaryExp FuncCallExp Cond LOrExp LAndExp EqExp PrimaryExp LVal RelExp  FuncCallParams 
%nterm <type> Type

%precedence THEN
%precedence ELSE   // 让else的优先级更高，即else优先与最近的if匹配
%%

//----------------------------产生式+语义动作--------------------

//----------------------------开始符号---------------------------
Program
    : Stmts {
        ast.setRoot($1); // 设置树根
    }
    ;
//----------------------------类型-------------------------------

Type // 供声明时用
    : INT {
        $$ = TypeSystem::intType;
    }
    | VOID {
        $$ = TypeSystem::voidType;
    }
    ;
    // 后续再考虑加入FLOAT等

//----------------------------语句---------------------------
Stmts
    : Stmt {$$=$1;}
    | Stmts Stmt{
        $$ = new SeqNode($1, $2);
        // SeqNode是一个抽象节点，用于构造一个指向多个语句的节点
        // SeqNode继承自StmtNode，构造函数中可以用子类实参来初始化父类形参
    }
    ;
Stmt // 所有可能的语句
    : AssignStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | WhileStmt {$$=$1;}
    | BreakStmt {$$=$1;}
    | ContinueStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    | EmptyStmt {$$=$1;}
    | ExprStmt {$$=$1;}
    ;
LVal // 左值
    : ID {
        SymbolEntry *se;
        // identifiers为一个符号表项的指针，永远指向当前符号表栈的栈顶
        // 从当前作用域的符号表开始，寻找所有符号表中是否有这个标识符，并返回其地址
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            // 如果找不到则报错，说明该标识符未声明
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        // new节点，通过构造函数来设置属性
        // 注意：该NT的属性为Id类型的节点，节点中又包含了符号表项指针这一成员
        $$ = new Id(se);
        delete []$1;
    }
    ;
ExprStmt // 表达式语句 
    : Exp SEMICOLON {
        $$ = new ExprStmt($1);
    }

AssignStmt // 赋值语句
    : 
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);// 通过新节点的构造函数来构建父子节点关系
    }
    ;
BlockStmt  // 语句块
    :   LBRACE 
        // 每一个块{}都新建一个符号表来保存当前标识符，原有的符号表会由现在符号表的pre指针指向
        {identifiers = new SymbolTable(identifiers);} 
        Stmts RBRACE 
        {
            // 遇到}，当前的块语句结束，删除符号表栈中栈顶的符号表
            $$ = new CompoundStmt($3); 
            // 类似于pop出栈的过程
            SymbolTable *temp = identifiers;
            identifiers = identifiers->getPrev();
            delete temp;
        }
    ;
IfStmt
    // 优先匹配第二个
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;
WhileStmt  // While语句
    : WHILE LPAREN Cond RPAREN Stmt {
        $$ = new WhileStmt($3, $5);
    }
    ;
BreakStmt   // Break语句
    : BREAK SEMICOLON {
        $$ = new BreakStmt();
    }
    ;
ContinueStmt   // Continue语句
    : CONTINUE SEMICOLON {
        $$ = new ContinueStmt();
    }
    ;
ReturnStmt    // 返回语句
    :
    RETURN Exp SEMICOLON{
        $$ = new ReturnStmt($2);
    }
    ;
EmptyStmt    // 空语句
    : SEMICOLON {
        $$ = new EmptyStmt();
    }
    | LBRACE RBRACE {
        $$=new EmptyStmt();
    }
    ;
Exp   // 表达式
    :
    AddExp {$$ = $1;}
    ;
Cond   // 条件
    :
    LOrExp {$$ = $1;}
    ;

AddExp  // 加减法
    : MulExp {$$ = $1;}
    | AddExp ADD MulExp
    {
        // 中间变量，方便中间代码使用
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    | AddExp SUB MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;

MulExp  // 乘除模
    : UnaryExp {$$ = $1;}
    | MulExp MUL UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);
    }
    | MulExp DIV UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);
    }
    | MulExp MOD UnaryExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);
    }
    ;

UnaryExp  //单目运算表达式
    :
    PrimaryExp {$$ = $1;}
    |
    ADD UnaryExp  //'+'号
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::ADD, $2);
    }
    |
    SUB UnaryExp  //'-'号
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::SUB, $2);
    }
    |
    NOT UnaryExp  //'!'号
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new UnaryExpr(se, UnaryExpr::NOT, $2);
    }
    |
    FuncCallExp {$$ = $1;}
    ;

FuncCallExp //函数调用
    : ID LPAREN RPAREN {   // 无参函数表达式  eg: f()
        SymbolEntry* se;
        se = identifiers->lookup($1);
        //函数调用前必须要有声明/定义
        if(se == nullptr)
        {
            fprintf(stderr, "function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new FuncCallExp(se);
    }
    | ID LPAREN FuncCallParams RPAREN {   // 含参函数表达式
        SymbolEntry* se;    
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "function \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        $$ = new FuncCallExp(se, $3);
    }
    ;

FuncCallParams //函数调用参数列表：参数1，参数2...
    : Exp {$$ = $1;}
    //COMMA为逗号
    | FuncCallParams COMMA Exp {
        $$ = $1;
        $$->setNext($3);// 串联上新的节点
    }
    ;

PrimaryExp  // 数字、ID以及(Expr)
    : LPAREN Exp RPAREN {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
    }
    | INTEGER {
        SymbolEntry* se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se);
    }
    ;

LOrExp
    : LAndExp {$$ = $1;}
    | LOrExp OR LAndExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;

LAndExp
    : EqExp {$$ = $1;}
    | LAndExp AND EqExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;

EqExp
    : RelExp {$$ = $1;}
    | EqExp EQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);
    }
    | EqExp NOTEQUAL RelExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3);
    }
    ;

RelExp
    : AddExp {$$ = $1;}
    | RelExp LESS AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    | RelExp LESSEQUAL AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESSEQUAL, $1, $3);
    }
    | RelExp GREATER AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    | RelExp GREATEREQUAL AddExp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATEREQUAL, $1, $3);
    }
    ;



//----------------------------声明---------------------------
DeclStmt
    :
    // 变量声明 
    Type VarDefs SEMICOLON {
        $$ = $2;
    }
    |
    // 常量声明
    CONST Type ConstDefs SEMICOLON {
        $$ = $3;
    }
    ;
VarDefs // 声明列表  a,b,c……
    : VarDefs COMMA VarDef {
        $$ = $1;
        $1->setNext($3); //参数表的参数通过指针串起来
    } 
    | VarDef {$$ = $1;}
    ;
ConstDefs
    : ConstDefs COMMA ConstDef {
        $$ = $1;
        $1->setNext($3);// 串连上ConstDef节点
    }
    | ConstDef {$$ = $1;}
    ;

VarDef
    : ID {   
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new DeclStmt(new Id(se));
        delete []$1;
    }
    | ID ASSIGN Exp {  // eg: int a,b=1+2;
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new DeclStmt(new Id(se), $3);
        delete []$1;
    }
    ;

// 常量声明
ConstDef
    : ID ASSIGN Exp {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry(TypeSystem::constIntType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$ = new DeclStmt(new Id(se), $3);
        delete []$1;
    }
    ;

FuncDef
    :
    Type ID {
        identifiers = new SymbolTable(identifiers);
    }
    LPAREN MaybeFuncDefParams RPAREN { // MaybeFuncDefParams:用于解决函数声明有无形参的问题
        Type* funcType;
        std::vector<Type*> vec;
        DeclStmt* temp = (DeclStmt*)$5;
        // 不断获取参数类型写入vec
        while(temp){
            vec.push_back(temp->getId()->getSymbolEntry()->getType());
            temp = (DeclStmt*)(temp->getNext());// 利用类的多态性，参数链表串接成链，可以直接遍历
        }
        funcType = new FunctionType($1, vec); // 用函数返回值类型和参数列表类型来构造FunctionType节点
        SymbolEntry* se = new IdentifierSymbolEntry(funcType, $2, identifiers->getPrev()->getLevel());
        // 将函数名压入函数作用域以外的符号表中，为了后续调用该函数
        identifiers->getPrev()->install($2, se);
    } 
    BlockStmt {
        SymbolEntry* se;
        se = identifiers->lookup($2);
        assert(se != nullptr);
        $$ = new FunctionDef(se, $8, (DeclStmt*)$5);
        SymbolTable* top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete []$2;
    }
    ;

MaybeFuncDefParams
    : FuncDefParams {$$ = $1;} // 有参数
    | %empty {$$ = nullptr;}   // 没有参数

FuncDefParams           // 形参列表，处理跟实参类似
    : FuncDefParams COMMA FuncDefParam {
        $$ = $1;
        $$->setNext($3);
    }
    | FuncDefParam {$$ = $1;}
    ;
    
FuncDefParam
    : Type ID {
        SymbolEntry* se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new DeclStmt(new Id(se));
        delete []$2;    
    }
    | Type ID ASSIGN Exp {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new DeclStmt(new Id(se),$4);
        delete []$2;
    }
    ;
%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
