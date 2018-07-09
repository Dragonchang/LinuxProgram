#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#undef sighandler1

void sigchldHandler(int s)
{
    printf("sigchldHandler pid:%d signal:%d\n",getpid(),s);
}

int main(int argc, char *argv)
{
    pid_t pid;
    int status;
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = sigchldHandler;
    printf("SIGALRM = %d\n",SIGALRM);
    sigaction (SIGALRM, &sa, NULL);
    printf("sleep begin pid:%d pid:%d\n",getpid(),pid); 

    alarm(10);
    pause();
    printf("sleep end pid:%d pid:%d\n",getpid(),pid); 
    
    return 0;
}
