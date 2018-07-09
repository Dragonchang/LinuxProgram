#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*int system(const char *cmdstring)
{
    pid_t pid;
    int status;
    if ((pid = fork())<0)
    {
        ///printf("fork the child failed!\n");
        exit(0);
    } else if (pid == 0)
    {
        
        execl("/bin/sh","sh","-c",cmdstring,(char *)0);
        //printf("this is child process pid:%d pid =%d glob =%d\n",getpid(), pid, glob);
        exit(0);
        
    } else 
    {  
       //printf("waite begin pid:%d pid:%d\n",getpid(),pid);
      // if(wait(&status) != pid)
         // printf("waite error\n");
       if (waitpid(pid, &status, 0) != pid) {
           printf("waite error\n");
       }
       //printf("waite end pid:%d status = %d\n",getpid(), status);
    }
    //printf("exit pid:%d pid_t =%d\n",getpid(),pid);

    return 0;
}
int main()
{

system("date");
return 0;
}
*/
      #include <execinfo.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       void
       myfunc3(void)
       {
           int j, nptrs;
       #define SIZE 100
           void *buffer[100];
           char **strings;

           nptrs = backtrace(buffer, SIZE);
           printf("backtrace() returned %d addresses\n", nptrs);

           /* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
              would produce similar output to the following: */

           strings = backtrace_symbols(buffer, nptrs);
           if (strings == NULL) {
               perror("backtrace_symbols");
               exit(EXIT_FAILURE);
           }

           for (j = 0; j < nptrs; j++)
               printf("%s\n", strings[j]);

           free(strings);
       }

       static void   /* "static" means don't export the symbol... */
       myfunc2(void)
       {
           myfunc3();
       }

       void
       myfunc(int ncalls)
       {
           if (ncalls > 1)
               myfunc(ncalls - 1);
           else
               myfunc2();
       }

       int
       main(int argc, char *argv[])
       {


           //myfunc(4);
           //exit(EXIT_SUCCESS);


       }
