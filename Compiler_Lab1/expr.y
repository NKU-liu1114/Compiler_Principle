%{
/****************************************************************************
expr.y
ParserWizard generated YACC file.
功能：计算表达式的值，同时支持处理空格回车等符号
Date: 2023年10月10日
****************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#ifndef YYSTYPE
// 用于确定$$的变量类型，由于返回的是简单表达式计算结果，因此定义为double类型
#define YYSTYPE double 
#endif
int yylex();

// yyparse调用yylex函数来得到token
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}

// 声明运算符的结合性和优先级，优先级由低到高的顺序声明
// 按照要求，单独为+ 、 - 、 * 、 / 、 ( 、 ) 定义单词
%token NUMBER
%token ADD
%token SUB
%token MUL
%token DIV
%token LEFT_PAR
%token RIGHT_PAR
%left ADD SUB
%left MUL DIV
%right UMINUS // 取负

%%
//规则段：翻译模式的设计

lines :    lines expr ';' { printf("%f\n", $2); } 
      |    lines ';'
      |
      ;

expr  :    expr ADD expr  { $$ = $1 + $3; } // $$代表产生式左部的属性值，$n 为产生式右部第n个token的属性值
      |    expr SUB expr  { $$ = $1 - $3; }
      |    expr MUL expr  { $$ = $1 * $3; }
      |    expr DIV expr  { $$ = $1 / $3; }
      |    LEFT_PAR expr RIGHT_PAR   { $$ = $2; }
      |    '-'expr %prec UMINUS  { $$ =-$2; }  // %prec 提升优先级
      |    NUMBER { $$ = $1; }
      ;

%%

// 用户子程序段
int yylex()
{	
    int m;
    while(1){
        m=getchar();
        if(m==' '||m=='\n'||m=='\t'){
            // 支持空格、制表符和换行
        }
        else if(m>='0'&&m<='9'){
            yylval=0;
            while(m>='0'&&m<='9'){  // 用于识别多位的十进制整数，循环遍历增加yylval
                yylval=yylval*10+m-'0';
                m=getchar();
            }
            ungetc(m, stdin); // 退回多读的字符
            return NUMBER;    // 返回单词NUMBER，同时属性值存储在yylval中
        }
        else if(m=='+'){
            return ADD;       // 返回单词类别
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
        yyparse();                  // 调用语法分析器
    } while(!feof(yyin));           // feof()是检测流上的文件结束符的函数，如果文件结束，则返回非0值
    return 0;
}

// 报错函数被yyparse()调用，以便在遇到错误时汇报错误
void yyerror(const char* s){
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}






