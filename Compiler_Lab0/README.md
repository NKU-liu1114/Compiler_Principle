# 文件说明
~~（备忘录）~~
## 源代码部分
jiechen.c为阶乘程序的c语言源码，jiechen.cpp为阶乘程序的出++语言源码，fib.c为斐波拉契数列程序源码。

## 预编译部分
pre_c.i为jiechen.c预处理后产生的文件，pre_c++.i为jiechen.cpp预处理后产生的文件。

## 编译部分
jiechen.s是由jiechen.cpp编译出的x86汇编代码，jiechen_x86.S是jiechen.c用gcc编译出的x86汇编代码\
jiechen_arm.S是由jiechen.c交叉汇编出的arm汇编代码，jiechen_byllvm.S是用llvm编译出的x86汇编代码\
jiechen.ll是llvm生成的llvm IR中间语言，fib.ll同理，fib.bc是llvm生成的llvm IR二进制代码形式\
jiechen.log是llvm IR通过pass进行代码优化后的内容

## 汇编部分
jiechen_x86.o是由jiechen_86.S用gcc汇编成的目标代码文件，jiechen_arm.o是交叉编译出的arm格式的目标代码文件

## 可执行文件部分
fib和jiechen_x86即为ELF格式的可执行文件

## 实验报告部分
main.tex为Latex代码\
NKU.png和imgs包含报告截图\
Compiler_Lab0.pdf为生成的实验报告



