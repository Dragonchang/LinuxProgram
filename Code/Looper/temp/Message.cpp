#include"Message.h"
Message::~Message(){
}

void Message::setTarget(Handler* handler) {
    mTarget = handler;
}
