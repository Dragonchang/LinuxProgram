
#include<stdio.h>
#include <unistd.h>
int main()
{
    char *dir = "/work/linux-l/binder-driver";
    int ret = chdir(dir);
    if (0!= ret)
    {
      printf("change failed!");
      	return 0;
    }
    char *ptr ="linux";
    *ptr = 0;
    return 0;
}
