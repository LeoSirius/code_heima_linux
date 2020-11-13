 .section .data
data_items:
 .long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

 .section .text
 .globl _start
_start:
 movl $0, %edi                  # move 0 to the index register
 movl data_items(,%edi,4), %eax # load first byte of data
 movl %eax, %ebx

start_loop:
 cmpl $0, %eax                  # check to see if we've hit the end
 je loop_exit
 incl %edi                      # load next value
 movl data_items(,%edi,4), %eax
 cmpl %ebx, %eax                # compare values
 jle start_loop                 # jump to beginning if the new value isn't biggest

 movl %eax, %ebx                # move the value as the largest
 
