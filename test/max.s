 .section .data
data_items:
 .long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

 .section .text
 .globl _start
_start:
 movl $0, %edi                  # move 0 to the index register
 movl data_items(,%edi,4), %eax # 把edi索引的元素移动到eax，4表示元素占4字节
 movl %eax, %ebx                # 然后把eax的值初始化为最大值存到ebx中

start_loop:

 # cmpl会相减两个操作数，是0则退出
 # je可以理解为jump if equal，和cpml配合使用。cmpl改变会标志位。je根据标志位判断
 cmpl $0, %eax
 je loop_exit

 incl %edi                      # load next value
 movl data_items(,%edi,4), %eax

 # 比较当前数和最大值，jle是“jump if less than or equal”
 cmpl %ebx, %eax
 jle start_loop

 movl %eax, %ebx                # move the value as the largest
 jmp start_loop                 # jmp是无条件jump

loop_exit:
 movl $1, %eax                  # call _exit, ebx is parameter, and store max value
 int $0x80

