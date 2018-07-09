#include<setjmp.h>

jmp_buf jmpbuffer;

void jmpfun()
{
    longjmp(jmpbuffer, 0);
}
int main(int argc, char *argv)
{
    int a = 0;
    if(setjmp(jmpbuffer) != 0)
        printf("setjmp failed!\n");
    jmpfun();
    return 0;
}
