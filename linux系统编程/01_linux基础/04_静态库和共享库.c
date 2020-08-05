- 静态库：在可执行程序运行前就加到执行代码中，成为执行程序的一部分
- 共享库：在执行程序启动时加载到执行程序中，可以被多个执行程序共享使用，在内存中只有一份。

静态库函数是链接后就有确定的地址，共享库函数的地址到调用的时候才有。
共享库省空间，但是调用共享库中的函数时，速度会慢一点

制作静态库

1. 将.c生成.o文件
   gcc -c add.c -o add.o
   gcc -c sub.c -o sub.o

2. ar rcs 静态库名 .o文件
   ar rcs libmymath.a add.o sub.o

3. 使用静态库
   gcc test.c libmymath.a -o test.out

4. 运行
    ./a.out

制作动态库

1. 将.c生成.o文件 （生成与位置无关的代码, -fPIC）
    gcc -c add.c -o add.o -fPIC

2. 使用gcc -shared 来制作动态库
    gcc -shared -o libmymath.so add.o

3. 使用动态库。不用编到out文件里，但是要指定
    - -l指定动态库名
    - -L指定动态库路径
    gcc test.c -o a.out -lmymath -L.

- 链接器：在链接阶段工作，-l -L 两个选项工作
- 动态链接器：在运行时工作，需要提供动态库所在目录位置。环境变量LD_LIBRARY_PATH

4. 运行

$ export LD_LIBRARY_PATH=./
$ ./a.out 
add(4, 6) = 10