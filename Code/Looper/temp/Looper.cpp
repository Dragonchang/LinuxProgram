#include "Looper.h"
Looper::Looper() {
    mMessageQueue = new MessageQueue();
}

Looper::~Looper() {
   if (mMessageQueue != 0) {
      delete mMessageQueue;
      mMessageQueue = 0;
   }
}


void Looper::loop() {
    Message * message;
    for (;;) {
        message = mMessageQueue->getNextMessage();
        message->mTarget->handlerMessage(message->what);
    }
}

