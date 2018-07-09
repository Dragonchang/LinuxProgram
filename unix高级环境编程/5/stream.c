#include<stdio.h>
#include <fcntl.h>

typedef struct Test
{
    int a;
    int c;
    char *t;
}Test;
Test *obj = 0;
int main(void)
{
    int fd;
    FILE *f;
    if((fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC))<0)
    {
      printf("open the file failed!\n");
      return 0;
    }
    
    obj = (Test *)malloc(sizeof(Test));
    if (obj != 0)
    {
      obj->a = 10;
      obj->c = 5;
      obj->t = "test\n";
    }
    f = fopen("test.txt","rb+");
    if (f != 0)
    {
        if(fwrite(obj,sizeof(Test),1,f)!= 1)
          printf("fwrite the file failed\n");
    }
    else
    {
        printf("fdopen the file failed!\n");
    }
    return 0;
}
