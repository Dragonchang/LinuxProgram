#ifndef H_MESSAGE
#define H_MESSAGE
#include"Handler.h"
#include<stdio.h>
class Handler;
class Message {
private: 
    //构造函数为私有的方法防止其它对象中创建该实例
    Message(int what) : what(what) {}
public:
    virtual ~Message();
    Message(){mNext = NULL;mTarget = NULL;}
    static Message* obtain(int what);
public:
    void setTarget(Handler* handler);
    int what;
    Handler *mTarget;
    Message* mNext;
};
#endif
