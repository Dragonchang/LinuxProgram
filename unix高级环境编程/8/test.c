//给出如下C程序，在linux下使用gcc编译：
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
 
int main()
{
    pid_t pid1;
    pid_t pid2;
 
    pid1 = fork();
    pid2 = fork();
 
    printf("pid1:%d, pid2:%d\n", pid1, pid2);
}
//要求如下：
//已知从这个程序执行到这个程序的所有进程结束这个时间段内，没有其它新进程执行。
//1、请说出执行这个程序后，将一共运行几个进程。
//2、如果其中一个进程的输出结果是“pid1:1001, pid2:1002”，写出其他进程的输出结果（不考虑进程执行顺序）。

//1001 1002 主
//1001 0    主进程fork的第二个子进程
//0    1003 主进程fork的第一个子进程fork的子进程
//0    0    主进程fork的第一个子    
