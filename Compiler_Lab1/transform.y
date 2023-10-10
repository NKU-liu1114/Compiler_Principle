%{
/****************************************************************************
transform.y
ParserWizard generated YACC file.

Date: 2023年10月10日
****************************************************************************/
// 定义段：包括头文件、函数定义、全局变量等
#include<stdio.h>
#include<stdlib.h>
#include<string.h>    // 使用strcpy和strcat
#ifndef YYSTYPE
#define YYSTYPE char* // 用于确定$$的变量类型,结果为后缀表达式，为字符串，故声明为char*
#endif

char idStr[60];//储存id的后缀表达式结果
char numStr[60];//储存number的后缀表达式结果
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}


// 声明运算符的结合性和优先级，优先级由低到高的顺序声明
%token NUMBER
%token ID
%token ADD
%token SUB
%token MUL
%token DIV
%token LEFT_PAR
%token RIGHT_PAR
%left ADD SUB
%left MUL DIV
%right UMINUS // 取负

// 规则段：翻译模式设计
%%

lines :    lines expr ';' { printf("%s\n", $2); }    //中缀转后缀，以%s格式输出expr
      |    lines ';'
      |
      ;

// 表达式的翻译模式，嵌入语义动作
expr  :    expr ADD expr  { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$,$3); strcat($$,"+");  }   // 需要先分配空间(这里预留60个字节)
      |    expr SUB expr  { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$,$3); strcat($$,"- "); }    
      |    expr MUL expr  { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$,$3); strcat($$,"* "); }
      |    expr DIV expr  { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$,$3); strcat($$,"/ "); }
      |    LEFT_PAR expr RIGHT_PAR   { $$ = $2; }    
      |    SUB  expr %prec UMINUS  { $$ = (char*)malloc(60); strcpy($$,"- "); strcat($$,$2); }         // 负数无需处理
      |    NUMBER         { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$," "); }                   // 留出空格
      |    ID             { $$ = (char*)malloc(60); strcpy($$,$1); strcat($$," "); }             
      ;

%%

// 子程序段

// yylex函数实现词法分析功能
int yylex()
{
    int m;
    while(1){
        m=getchar();
        if(m==' ' || m=='\t'||m=='\n')
            ;
        
        // NUMBER 的翻译模式执行动作就修改为将yylval的值拷贝给 NUMBER，这里翻译模式的代码中并未出现 yylval，
        // 却依然完成了赋值操作，这是因为 yacc 与 lex 默认将 yylval 的值赋给了识别出的标识符
        // 也就是例子中的 $1, 所以这里的 strcpy($$,$1)也等价于 strcpy($$,yylval)
        else if (m>='0' && m<= '9'){//isdigit
            int temp=0;
            while(m>='0'&&m<='9'){// 进入循环，直到下一位不是数字
                numStr[temp++]=m;
                m=getchar();
            }  
            numStr[temp]='\0'; // 字符串最后添加结束符\0
            yylval=numStr;     // 把后缀表达式的值（字符串）赋值给yylval
            ungetc(m,stdin);   // 类似，需要退回一位
            return NUMBER;
        }
        
        // 如果读到的字符为字母或下划线时，连续读接下来的字符，直到出现一个不是数字或字母或下划线的字符停止
        else if ((m>='a'&& m<='z')||(m>='A'&&m<='Z')||(m=='_')){
            int temp=0;
            while((m>='a'&& m<='z')||(m>='A'&&m<='Z')||(m=='_')||(m>='0'&&m<='9')){
                idStr[temp++]=m;
                m=getchar();
            }
            idStr[temp]='\0';
            yylval=idStr;
            ungetc(m,stdin);
            return ID;
        }
        else if(m=='+') {
            return ADD;  
        }
        else if(m=='-'){
            return SUB;
        }
        else if(m=='*'){
            return MUL;
        }
        else if(m=='/'){
            return DIV;
        }
        else if(m=='('){
            return LEFT_PAR;
        }
        else if(m==')'){
            return RIGHT_PAR;
        }
        else {
            return m;
        }
    }
}

int main()
{
    yyin = stdin;
    do{
        yyparse();
    } while(!feof(yyin));
    return 0;
}
void yyerror(const char* s){
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}