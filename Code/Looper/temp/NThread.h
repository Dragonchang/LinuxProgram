#ifndef H_NTHREAD
#define H_NTHREAD
#include"Looper.h"
#include<pthread.h>
#include<stdio.h>
class NThread {
public:
    NThread();
    virtual ~NThread();

protected:
    Looper* mLooper;
    pthread_t mTid;
public:
    static void* ThreadLoop(void* arg);
    Looper* getLooper() { return mLooper;}
    pthread_t getTid() {return mTid;}
};
#endif
