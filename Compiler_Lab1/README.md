# 文件说明
## ARM汇编
fib.c是SysY源程序，fib.S是ARM汇编代码，fib.o是交叉编译的ARM架构的目标文件，fib是交叉编译的可执行文件。

## Yacc编程
expr.y是实现表达式求值的Yacc源程序，expr.tab.c和expr.tab.h是通过Bison软件编译出的c语言程序，再通过gcc\
编译链接成可执行文件，最后通过./expr < input.txt 读取文本中的字符流，输出表达式的值。\
transform实现了中缀表达式转后缀表达式的功能，相关文件与上类似。

