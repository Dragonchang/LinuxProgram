#include<pthread.h>
#include<stdio.h>
#include <unistd.h>
pthread_t tid;
pthread_key_t data_key;
class data
{
    public:
    data(int a){
        a = a;
        printf("this is construct %d\n", a);
    };
    ~data() {
        printf("this is destruct fun%d\n", a);
    };
    private:
    int a;
};
void * run(void *arg)
{
    data d(3);
    pthread_setspecific (data_key, &d);
    printf("run1 tid:%d\n",(unsigned)pthread_self());
    sleep(3);
    printf("run1 tid:%d\n",(unsigned)pthread_self());
}



void test()
{
  int a =1000;
  char str[1000]={"0"};

}
int main()
{
    void *tret;
    printf("main thread  tid:%d\n",(unsigned)pthread_self());
    int resut = pthread_create(&tid,0,run,0);
    int err = pthread_key_create(&data_key, 0);

    test();
    
    pthread_join(tid,&tret);
    return 0;
}
