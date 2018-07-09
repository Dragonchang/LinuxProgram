
#include<dirent.h>
#include <stdio.h>


typedef unsigned char* byte_pointer;//指针类型决定遍历的字节的大小

void show_bytes_int(byte_pointer start, int len) {
        printf("&len = %.16x\n",&len);
	int i;
	for (i = 0; i < len; i++)
	printf(" addr:%.16x ->( %.2x );", &start[i],start[i]);
	printf("\n");
}

void show_bytes_address(byte_pointer start, int len) {
	int i;
	for (i = 0; i < len; i++)
	printf(" %.16x",start[i]);
	printf("\n");
}

void show_bytes_value(byte_pointer start, int len) {
	int i;
	for (i = 0; i < len; i++)
	printf(" %.16x",start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes_int((byte_pointer) &x, 465000);//为什么内存的地址能访问的范围为4548个字节
}
void show_pointer_address(void *x) {
	//show_bytes_address((byte_pointer) &x, sizeof(void *));
}

void show_pointer_value(void *x) {
        show_bytes_int((byte_pointer) x, sizeof(void *));
	//show_bytes_value((byte_pointer) &x, sizeof(void *));
}

int Test(int a, int b) {
   int i,j;
   i = a;
   j = b;
   return 1;
}

int main(int argc, char *argv[])
{

    //int c =10;
    //int *b;
    //b = &c;
    //printf("&c = 0x%.16x\n",&c);
    //printf("&b = 0x%.16x\n",&b);
    //printf("b = %p\n",b);  //%p 打印出指针变量中保存的地址的值
    //asm volatile("movl %%gs:0, %0;"
            //:"=r"(b) /* output */ 
            //);
    //printf("&c = %d\n",b);
    //char c ='a';
    int a = 1;
    int a1 = 1;					
    int a2 = 1;
    int a3 = 1;
    int a4 = 1;
    int a5 = 1;
    int a6 = 1;
    int a7 = 1;
    int a8 = 1;
    int a9 = 1;
    int aa = 1;
    printf("&a1 = %.16x\n",&a1);
	printf("&a2 = %.16x\n",&a2);
	printf("&a3 = %.16x\n",&a3);
	printf("&a4 = %.16x\n",&a4);
	printf("&a5 = %.16x\n",&a5);
	printf("&a6 = %.16x\n",&a6);
	printf("&a7 = %.16x\n",&a7);
	printf("&a8 = %.16x\n",&a8);
	printf("&aa = %.16x\n",&aa);
	printf("&show_int = %.16x\n",&show_int);
    if(a == 1) {
     printf("\n");
    }
    while (0) {
     printf("\n");
    }
    //int *pInt;
    //*pInt = 2;
    //char *pChar;
    //printf("&c = %d\n",&c);
    //printf("&a = %d\n",&a);
    //printf("&pInt = %d\n",&pInt);
    show_int(a);
    //printf("show_pointer_value************* &pInt = %.16x\n",&pInt);
    //show_pointer_value(pInt);
    //show_pointer_address(&pInt);

}


