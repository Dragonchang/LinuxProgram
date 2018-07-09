#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<pthread.h>
//#undef sighandler1


void sigchldHandler(int s)
{
    pid_t pid;
    int status;
    printf("sigchldHandler pid:%d signal:%d tid:%d\n",getpid(),s ,(unsigned)pthread_self());
    //sleep(10);
    //while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        //printf("waitpid pid:%d status:%d tid:%d\n",pid,status ,(unsigned)pthread_self());
    //}
}

void sigchldHandler_int(int s)
{
    printf("sigchldHandler_int pid:%d signal:%d tid:%d\n",getpid(),s ,(unsigned)pthread_self());

}
int main(int argc, char *argv)
{
    pid_t pid;
    int status;
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = sigchldHandler;
    printf("SIGCHLD = %d tid:%d\n",SIGCHLD,(unsigned)pthread_self());
    sigaction (SIGCHLD, &sa, NULL);

    struct sigaction sa1;

    memset(&sa1, 0, sizeof(sa1));

    sa1.sa_handler = sigchldHandler_int;
    printf("SIGINT = %d tid:%d \n",SIGINT,(unsigned)pthread_self());
    sigaction (SIGINT, &sa1, NULL);


//while(1){
    sleep(1);

    if ((pid = fork())<0)
    {
        printf("fork the child failed!\n");
    } else if (pid == 0)
    {
      printf("sleep begin child pid:%d tid:%d\n",getpid(),(unsigned)pthread_self()); 
      sleep(10);
      printf("sleep end child pid:%d tid:%d\n",getpid(),(unsigned)pthread_self()); 
      abort();   
      printf(" child abort pid:%d tid:%d\n",getpid(),(unsigned)pthread_self()); 
    } else {  
      //printf("sleep begin pid:%d pid:%d\n",getpid(),pid); 
      ///sleep(1000);   //当在系统调用的时候发生了信号的软中断的问题
     printf("parent pid:%d child pid:%d tid:%d\n",getpid(),pid,(unsigned)pthread_self()); 
      int status = 0;
      //while(1)
      {
          sleep(20);
          status ++;
          printf("parent looper status= %d tid:%d\n", status,(unsigned)pthread_self());
      }
    }
//}
    return 0;
}
