#include"main.h"
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include <signal.h>


static void WidebrightSegvHandler(int signum)  
{  
    void *array[10];  
    size_t size;  
    char **strings;  
    size_t i, j;  
  
    signal(signum, SIG_DFL); /* 还原默认的信号处理handler */  
  
    size = backtrace (array, 10);  
    strings = (char **)backtrace_symbols (array, size);  
  
    fprintf(stderr, "widebright received SIGSEGV! Stack trace:\n");  
    for (i = 0; i < size; i++) {  
        fprintf(stderr, "%d %s \n",i,strings[i]);  
    }  
      
    free (strings);  
    exit(1);  
}

int main(){
signal(SIGSEGV, WidebrightSegvHandler);
printf("malloc begin!!\n");
void* mOwnedData = 0xfffffffb;//(void*)0;//malloc(10);
printf("malloc end %d!!\n",&mOwnedData);
free(mOwnedData);
printf("first free end!!\n");
//free(mOwnedData);
printf("sec free end!!\n");

return -1;
}
