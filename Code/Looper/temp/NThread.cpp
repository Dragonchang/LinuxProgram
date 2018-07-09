#include"NThread.h"
NThread::NThread(){
    mLooper = new Looper();
    pthread_create(&mTid,0,ThreadLoop,this);
}

NThread::~NThread(){
    if(mLooper != NULL) {
        delete mLooper;
        mLooper = NULL;
    }
}

void* NThread::ThreadLoop(void* arg){
    //NThread *ptr = (NThread *)arg;
    //ptr->getLooper()->loop();
}

