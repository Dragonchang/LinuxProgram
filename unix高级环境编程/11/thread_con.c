#include<pthread.h>
//线程挂起：1.mutex锁只有等待其他线程释放该锁
//条件变量信号不会保存
//pthread_cond_wait 会将在mutex等待的线程解锁
pthread_t tid;
pthread_mutex_t f_lock;

pthread_t tid2;
pthread_mutex_t f_lock2;

static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void * run(void *arg)
{
    int i = 0;
    printf("run1 pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
    //pthread_detach(pthread_self());
    pthread_mutex_lock(&f_lock);
    printf("run1 enter the lock pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
    //while(1)
    //{
      printf("waite begin\n");
      //pthread_cond_wait(&cond, &f_lock);
      printf("child1 loop i = %d\n",i++);
      sleep(5);
    //}
    pthread_mutex_unlock(&f_lock);
    printf("run1 out the lock pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
}

void * run2(void *arg)
{
    int i = 0;
    printf("run2 pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
    //pthread_detach(pthread_self());
    pthread_mutex_lock(&f_lock);
    printf("run2 enter the lock pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
   // while(1)
    {
        //pthread_cond_wait(&cond, &f_lock);
        printf("child2 loop i = %d\n",i++);
        sleep(5);
    }
    pthread_mutex_unlock(&f_lock);
    printf("run2 out the lock pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
}


int main(void)
{
    void *tret;
    int i = 0;
    if (pthread_mutex_init(&f_lock, 0) != 0)
        printf("mutex init failed\n");
    if (pthread_mutex_init(&f_lock2, 0) != 0)
        printf("mutex init failed\n");

    printf("main thread pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
    int resut = pthread_create(&tid,0,run,0);
    resut = pthread_create(&tid2,0,run,0);
    printf("main thread wait pid:%d tid:%d\n",getpid(),(unsigned)pthread_self());
    //while(1)
    {
      //sleep(5);
      //pthread_cond_signal(&cond);
      //pthread_cond_signal(&cond);
      //printf("parent send cond i = %d\n",i++);
      //sleep(1); 
      //if(i >10)break;
    }
    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);
    printf("main thread end\n");
}
