#include"Handler.h"
Handler::Handler(Looper* looper){
    mLooper = looper;
}

Handler::~Handler(){

}

void Handler::sendMessage(Message *message){
    message->setTarget(this);
    mLooper->getMessageQueue()->enqueueMessage(message);
}

void Handler::handlerMessage(int what){
    //printf("Handler::handlerMessage\n");
}
