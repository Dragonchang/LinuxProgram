#include<fcntl.h>

char buffer1[] ="abcdefgh\0";
char buffer2[] ="ABCDEFGH\0";
int main(void)
{
    int fd;
    int dupfd;
    if ((fd = creat("file.test", O_CREAT))<0)
        printf("create file failed!\n");
    printf("the fd = %d\n",fd);
    printf("the getpid = %d\n",getpid());
   int i;
    for (i = 0; i<1024;i++) {
        dupfd = dup(fd);
        if (dupfd<0) {
           printf("dup file failed! i= %d\n",i);
        }
    }
    while (1) {
 }
    //if ((fd = creat("file2.test", O_CREAT))<0)
        //printf("create file failed!\n");

    //printf("the fd = %d\n",fd);
    //if((write(fd, buffer1, 8)) != 8)
        //printf("write the buffer1 failed!\n");
    //if((lseek(fd, 1000,SEEK_SET))== -1)
        //printf("lseek file failed!\n");
    //if((write(fd, buffer2,8))!= 8)
        //printf("write buffer2 failed!\n");
 return 0;
}
