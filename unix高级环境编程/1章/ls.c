
#include<dirent.h>

#include <stdio.h>
#include <stdlib.h>

void test ()
{
 printf("test begin\n");
    unsigned int        i = 0x12345678;
    unsigned short int *q = NULL;
    unsigned char      *p = ( unsigned char * )&i;

    *p = 0x00;
    q  = ( unsigned short int * )( p + 1 );
    *q = 0x0000;
 printf("test end\n");
} 


int main(int argc, char *argv[])
{
 /*   DIR  *dp;
    struct dirent *dirp;
    if(argc != 2)
    {
         printf("please input the dir\n");
         return 0;
    }
    if ((dp = opendir(argv[1]))== 0)
    {
         printf("the dir is not exist!\n");
         return 0;
    }
    while((dirp = readdir(dp)) != 0)
        printf("%s\n",dirp->d_name);

    closedir(dp);
    int i;
    int j;
    for(i = 0; i<3;i++) {
        printf("out loop i = %d \n", i);
        for(j = 0; j<3;j++) {
            printf("inner loop j = %d \n", j);
            if (j == 2) {
               printf("stop inner loop j = %d \n", j);
               return;
            }
        }
    }
*/
    test ();
    return 1;
}


