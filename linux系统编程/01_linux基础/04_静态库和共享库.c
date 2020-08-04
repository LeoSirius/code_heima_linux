- 静态库：在可执行程序运行前就加到执行代码中，成为执行程序的一部分
- 共享库：在执行程序启动时加载到执行程序中，可以被多个执行程序共享使用，在内存中只有一份

共享库省空间，但是调用共享库中的函数时，速度会慢一点

制作静态库

1. 将.c生成.o文件
   gcc -c add.c -o add.o
   gcc -c sub.c -o sub.o

2. ar rcs 静态库名 .o文件
   ar rcs libmymath.a add.o sub.o

使用静态库

   gcc test.c libmymath.a -o test.out

制作动态库


