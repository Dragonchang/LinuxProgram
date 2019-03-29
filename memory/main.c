#include <stdio.h> 
#include <sys/time.h>   
#include <sys/resource.h> 

int main(int argc, char *argv[])
{
 struct rusage buf; 
  
 int ret = getrusage(RUSAGE_SELF, &buf); 
 if (ret == 0) {
    printf("get usage success\n");
    printf("get usage usage.ru_nswap:%d\n",buf.ru_nswap);
 } else {
   printf("get usage failed!\n");
 }
return 0;
}


