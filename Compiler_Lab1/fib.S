.arch armv5t            @表示使用 ARMv5t 指令集

@ 数据段
.comm  n, 4             @ 未初始化变量
.data
    a:  .word 0         @ arm架构下word表示32bits,与x86(16bits)相区别
    b:  .word 1
    i:  .word 1
    t:  .word 0




@ 只读数据段
.rodata:
    .align 2
info:
    .asciz  "Please enter the number of items in the Fibonacci sequence:"   
    .align 2
input:
    .asciz "%d"
    .align 2
output1:
    .asciz "The result is:\n%d\n"
    .align 2
output2:
    .asciz "%d\n"
    .align 2


@ 代码段
.text 
    .align 2                          
    .global main  
main:
    push  {fp,lr}                     @ 从左到右压入栈中，作用是保存返回地址和栈基地址
    add  fp, sp, #4                   @ 开辟函数栈帧
    ldr  r0, _bridge+20               @ 传入参数
    bl   printf                       @ 调用输出函数


    ldr  r1, _bridge                  @ r1=&n 
    ldr  r0, _bridge+24               @ r0=input
    bl   __isoc99_scanf               @ scanf("%d",&n)

    ldr  r0, _bridge+4
    ldr  r1, [r0]                     @ r1=b
    ldr  r0, _bridge+28               @ r0=output1
    bl   printf

 LOOP:
    ldr  r0, _bridge+8               
    ldr  r1, [r0]                     @ r1=i

    ldr  r0, _bridge  
    ldr  r2, [r0]                     @ r2=n

    cmp  r1, r2
    bge  L1                           @ 退出循环

    ldr  r0, _bridge+4
    ldr  r3, [r0]                     @ r3=b

    ldr  r0, _bridge+32                       
    str  r3, [r0]                     @ t=r3

    ldr  r0, _bridge+12
    ldr  r4, [r0]                     @ r4=a
    add  r3,r3,r4                     @ r3=r3+r4
    ldr  r0, _bridge+4
    str  r3,[r0]                      @ b=r3

    ldr  r1,[r0]                      @ r1=b
    ldr  r0,_bridge+16                @ r0=output2
    bl   printf

    ldr  r0,_bridge+32
    ldr  r1,[r0]                      @ r1=t

    ldr  r0,_bridge+12
    str  r1,[r0]                      @ a=r1

    ldr  r0,_bridge+8
    ldr  r2,[r0]                      @ r2=i
    add  r2,r2,#1                     @ r2=r2+1
    str  r2,[r0]                      @ i=r2
    b    LOOP


L1:
    mov  r0, #0
    pop  {fp, pc}                     @ return 0

_bridge:
    .word n        
    .word b
    .word i     
    .word a
    .word output2
    .word info
    .word input
    .word output1
    .word t

    .section .note.GNU-stack,"",%progbits 


