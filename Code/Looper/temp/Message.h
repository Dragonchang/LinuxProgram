#ifndef H_MESSAGE
#define H_MESSAGE
#include"Handler.h"
#include<stdio.h>
class Handler;
class Message {
public:
    Message(){ }
    virtual ~Message();
    Message(int what) : what(what) { }
public:
    void setTarget(Handler* handler);
    int what;
    Handler *mTarget;
    Message* mNext;
};
#endif
