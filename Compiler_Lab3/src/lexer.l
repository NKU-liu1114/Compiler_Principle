/* 代码与词法分析类似，不同的是：在识别到单词时，需要return 单词而不是输出到文件 */
%option noyywrap
%{
    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    #include "parser.h"
    #include <ostream>
    #include <fstream>
    #include <iostream>
    using namespace std;

    extern FILE *yyin; 
    extern FILE *yyout;
    extern bool dump_tokens;
    // 修改dumptokens函数，用于调试
    void DEBUG(std::string s){
        std::string DEBUG_INFO = "[DEBUG]: \t" + s + "\n";
        fputs(DEBUG_INFO.c_str(), yyout);
    }
%}

/* 十进制 */
DECIMIAL ([1-9][0-9]*|0)  
/* 八进制 */
OCTAL (0[0-7]+)           
/* 十六进制 */
HEXADECIMAL (0[xX][0-9A-Fa-f]+)            
/* 标识符 */
ID [[:alpha:]_][[:alpha:][:digit:]_]*
/* 回车换行符 */
EOL (\r\n|\n|\r)   
/* 制表符(空格) */
WHITE [\t ]        

%x BLOCKCOMMENT            
/* 块注释 */
BLOCKCOMMENTBEGIN "/*"           
BLOCKCOMMENTELEMENT .|\n         
BLOCKCOMMENTEND "*/" 
/* 行注释 */
LINECOMMENT \/\/[^\n]*

%%

"int" {
    if(dump_tokens)
        DEBUG("INT\tint");
    return INT;
}
"void" {
    if(dump_tokens)
        DEBUG("VOID\tvoid");
    return VOID;
}
"const" {
    if(dump_tokens)
        DEBUG("CONST\tconst");
    return CONST;
}
"if" {
    if(dump_tokens)
        DEBUG("IF\tif");
    return IF;
};
"else" {
    if(dump_tokens)
        DEBUG("ELSE\telse");
    return ELSE;
};
"return" {
    if(dump_tokens)
        DEBUG("RETURN\treturn");
    return RETURN;
}
"while" {
    if(dump_tokens)
        DEBUG("WHILE\twhile");
    return WHILE;
}
"break" {
    if(dump_tokens)
        DEBUG("BREAK\tbreak");
    return BREAK;
}
"continue" {
    if(dump_tokens)
        DEBUG("CONTINUE\tcontinue");
    return CONTINUE;
}

"==" {
    if(dump_tokens)
        DEBUG("EQUAL\t==");
    return EQUAL;
}
"!=" {
    if(dump_tokens)
        DEBUG("NOTEQUAL\t!=");
    return NOTEQUAL;
}
"=" {
    if(dump_tokens)
        DEBUG("ASSIGN\t=");
    return ASSIGN;
}
"<" {
    if(dump_tokens)
        DEBUG("LESS\t<");
    return LESS;
}
"<=" {
    if(dump_tokens)
        DEBUG("LESSEQUAL\t<");
    return LESSEQUAL;
}
">" {
    if(dump_tokens)
        DEBUG("GREATER\t<");
    return GREATER;
}
">=" {
    if(dump_tokens)
        DEBUG("GREATEREQUAL\t<");
    return GREATEREQUAL;
}
"+" {
    if(dump_tokens)
        DEBUG("ADD\t+");
    return ADD;
}
"-" {
    if(dump_tokens)
        DEBUG("SUB\t-");
    return SUB;
}
"*" {
    if(dump_tokens)
        DEBUG("MUL\t*");
    return MUL;
}
"/" {
    if(dump_tokens)
        DEBUG("DIV\t/");
    return DIV;
}
"%" {
    if(dump_tokens)
        DEBUG("MOD\t%");
    return MOD;
}
"&&" {
    if(dump_tokens)
        DEBUG("AND\t&&");
    return AND;
}
"||" {
    if(dump_tokens)
        DEBUG("OR\t||");
    return OR;
}
"!" {
    if(dump_tokens)
        DEBUG("NOT\t!");
    return NOT;
}
";" {
    if(dump_tokens)
        DEBUG("SEMICOLON\t;");
    return SEMICOLON;
}
"(" {
    if(dump_tokens)
        DEBUG("LPAREN\t(");
    return LPAREN;
}
")" {
    if(dump_tokens)
        DEBUG("RPAREN\t)");
    return RPAREN;
}
"{" {
    if(dump_tokens)
        DEBUG("LBRACE\t{");
    return LBRACE;
}
"}" {
    if(dump_tokens)
        DEBUG("RBRACE\t}");
    return RBRACE;
}
"[" {
    if(dump_tokens)
        DEBUG("LBRACKET\t[");
    return LBRACKET;
}
"]" {
    if(dump_tokens)
        DEBUG("RBRACKET\t}");
    return RBRACKET;
}
"," {
    if(dump_tokens)
        DEBUG("COMMA\t,");
    return COMMA;
}
{DECIMIAL} {
    if(dump_tokens)
        DEBUG(string("NUMBER\t") + string(yytext));
    //INTEGER这个单词的属性值类型（语义类型）为itype（int类型），其属性就是整数值，后面同
    //atoi将字符串转为整形
    yylval.itype = atoi(yytext);
    return INTEGER;
}
{OCTAL} {
    int num;
    //sscanf()会将参数str的字符串根据参数format字符串来转换并格式化数据
    sscanf(yytext, "%o", &num);
    if(dump_tokens)
        DEBUG(string("NUMBER\t") + to_string(num));
    yylval.itype = num;
    return INTEGER;
}
{HEXADECIMAL} {
    int num;
    sscanf(yytext, "%x", &num);
    if(dump_tokens)
        DEBUG(string("NUMBER\t") + to_string(num));
    yylval.itype = num;
    return INTEGER;
}


{ID} {
    if(dump_tokens)
        DEBUG(yytext);
    char *lexeme;
    lexeme = new char[strlen(yytext) + 1];
    strcpy(lexeme, yytext);
    //ID这个单词的属性值类型（语义类型）为strtype（char*类型），其属性就是词素
    yylval.strtype = lexeme;
    return ID;
}
<*>{EOL} {              // EOL回车换行符
    yylineno++;
}
{WHITE} {}
{LINECOMMENT} {}   
{BLOCKCOMMENTBEGIN} {BEGIN BLOCKCOMMENT;}
<BLOCKCOMMENT>{BLOCKCOMMENTELEMENT} {}
<BLOCKCOMMENT>{BLOCKCOMMENTEND} {BEGIN INITIAL;} 

%%
