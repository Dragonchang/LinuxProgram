#include <stdio.h>

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
void test(){
 int test =111;

}
int a = 0;
int main() {

int A[1];
A[0] = 3;
A[1] = 4;
struct test t;
t.c0 ='a';
t.c1 ='\0';
t.c2 ='c';
t.c3 ='d';
t.c4 ='a';
t.c5 ='b';
t.c6 ='c';
t.c7 ='d';

t.a =2;
t.d =5;
t.p =NULL;

printf("&t =%.16x\n",&t);
printf("&t =%.16x\n",&test);
char *p = (char *)&t;
printf("p =%s\n",p);//char 指针类型的数据不是以char类型的大小来寻址访问，通过内存中\0结束符来作为寻址结束的标志

return 0;

}
