#include <stdio.h> 
#include <sys/time.h>   
#include <sys/resource.h> 
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
http://royluo.org/2014/06/15/kvm-install-1/
void *read_thread(void *dummy)
{
        //sleep(100000); 
        return NULL;
}

int main(int argc, char *argv[])
{

        pthread_t pid = 0;
        int ret = 0;
        //ret = pthread_create(&pid, NULL, read_thread, NULL);
        //if (ret < 0)
        //{
            //perror("pthread create:");
            //return 0;
        //}
        //struct rusage buf; 
        //test *t = new test(); 
        //test *t1 = NULL;
        //ret = getrusage(RUSAGE_SELF, &buf); 
        //if (ret == 0) {
            //printf("get usage success\n");
            //printf("get usage usage.ru_nswap:%d\n",buf.ru_nswap);
        //} else {
            //printf("get usage failed!\n");
        //}
       printf("mmap begin!\n");
       void* mVMStart = mmap(0, 10000000000000, PROT_READ, MAP_PRIVATE | MAP_NORESERVE,
                  0, 0);
       printf("mmap end!\n");

sleep(1); 
        return 0;
}


