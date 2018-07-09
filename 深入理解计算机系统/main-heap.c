#include <stdio.h>
#include <stdlib.h>
#include  <sys/statfs.h>
struct test{
char c0 ;
char c1 ;
char c2 ;
char c3 ;
char c4 ;
char c5 ;
char c6 ;
char c7 ;
int a ;
double d;
char *p;
};
int numMa = 1024*1024;
void main() {
    printf("main heap *********begin\n");
    int a = 1;
    int *point = &a;
    int *heap;
    int i = 0;
    int errno = 0;
/*
    for (;i<numMa;i++) {
        printf("i = %d\n",i);
        heap = malloc(1024*1024*1024);
        printf("heap = %.16x\n",heap);
        if (heap == NULL) {
            printf("errno = %d, errno message = %s\n", errno, strerror(errno));
            printf("malloc failed i = %d\n",i);
            break; 
        }
        //printf("&heap = %.16x\n", &heap);
        
    }

    printf("point = %.16x\n",point);
    printf("&point = %.16x\n", &point);
*/
    //printf("heap = %.16x\n",heap);
    //printf("&heap = %.16x\n", &heap);
    
    //在堆上分配一块内存，越界使用这块内存会有什么结果
    heap = malloc(1);
    printf("&heap[7] = %.16x\n",&heap[7]);
    printf("heap[7] = %.8x\n",heap[7]);
    printf("&heap[6] = %.16x\n",&heap[6]);
    printf("heap[6] = %.8x\n",heap[6]);
    printf("&heap[5] = %.16x\n",&heap[5]);
    printf("heap[5] = %.8x\n",heap[5]);
    printf("&heap[4] = %.16x\n",&heap[4]);
    printf("heap[4] = %.8x\n",heap[4]);
    printf("&heap[3] = %.16x\n",&heap[3]);
    printf("heap[3] = %.8x\n",heap[3]);
    printf("&heap[2] = %.16x\n",&heap[2]);
    printf("heap[2] = %.8x\n",heap[2]);
    printf("&heap[1] = %.16x\n",&heap[1]);
    //printf("heap[1] = %.8x\n",heap[166666]);
    struct test *t = 2;
    //t->a = 1;
    t = (struct test *)malloc(sizeof(struct test));
    t->a = 1;



}
