#ifndef H_LOOPER
#define H_LOOPER
#include<stdio.h>
#include "MessageQueue.h"
#include "Message.h"
class MessageQueue;
class Looper {
public:
    virtual ~Looper();

public:
    Looper();
    void loop();
    MessageQueue* getMessageQueue() { return mMessageQueue;}
private:
    MessageQueue* mMessageQueue;
};
#endif
