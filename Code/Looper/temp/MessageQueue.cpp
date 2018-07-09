#include"MessageQueue.h"
static const int EPOLL_SIZE_HINT = 8;
// Maximum number of file descriptors for which to retrieve poll events each iteration.
static const int EPOLL_MAX_EVENTS = 16;
MessageQueue::MessageQueue():mEpollFd(-1) {
    mHead = new Message();
    mTail = new Message();
    mHead->mNext = mTail;
    buildEpollLocked();
}

void MessageQueue::buildEpollLocked() {
    if (mEpollFd >= 0) {
        close(mEpollFd);
    }
    mWakeEventFd = eventfd(0, EFD_NONBLOCK);
    // Allocate the new epoll instance and register the wake pipe.
    mEpollFd = epoll_create(EPOLL_SIZE_HINT);
    struct epoll_event eventItem;
    memset(& eventItem, 0, sizeof(epoll_event)); // zero out unused members of data field union
    eventItem.events = EPOLLIN;
    eventItem.data.fd = mWakeEventFd;
    int result = epoll_ctl(mEpollFd, EPOLL_CTL_ADD, mWakeEventFd, & eventItem);
}

MessageQueue::~MessageQueue() {
   if (mHead != NULL) {
      delete mHead;
      mHead = NULL;
   }
   if (mTail != NULL) {
      delete mTail;
      mTail = NULL;
   }
    close(mWakeEventFd);
    if (mEpollFd >= 0) {
        close(mEpollFd);
    }
}

void MessageQueue::queueAtFront(Message* message) {
     message->mNext = mHead->mNext;
     mHead->mNext = message;
}

Message* MessageQueue::removeAtTail() {
    Message* indexMessage;
    Message* removeMessage;
    bool onlyOneMessage = false;
    if (mHead->mNext == mTail) {
        printf("MessageQueue is empty!\n");
        return NULL;
    }
    for(indexMessage = mHead->mNext; indexMessage != mTail;indexMessage = indexMessage->mNext) {
       if (indexMessage->mNext == mTail) {
           onlyOneMessage = true;
           printf("only one message at MessageQueue\n");
           break;
       }
       if(indexMessage->mNext->mNext == mTail) {
           printf("find the last second message at MessageQueue\n");
           break;
       }
    }
    if (onlyOneMessage) {
        removeMessage = indexMessage;
        mHead->mNext = mTail;
    } else {
        removeMessage = indexMessage->mNext;
        indexMessage->mNext = mTail;
    }
    return removeMessage;
}

int MessageQueue::pollOnce(int timeoutMillis) {
    int result = 0;
    for (;;) {
        if (result != 0) {
            return result;
        }
        struct epoll_event eventItems[EPOLL_MAX_EVENTS];
        result = POLL_WAKE;
        int eventCount = epoll_wait(mEpollFd, eventItems, EPOLL_MAX_EVENTS, timeoutMillis);
        printf("MessageQueue::pollOnce epoll_wait, eventCount=%d\n", eventCount);
        // Check for poll error.
        if (eventCount < 0) {
	    //if (errno == EINTR) {
	        //return result;
	    //}
	    result = POLL_ERROR;
	    return result;
        }

        // Check for poll timeout.
        if (eventCount == 0) {
	    result = POLL_TIMEOUT;
	    return result;
        }
        for (int i = 0; i < eventCount; i++) {
            int fd = eventItems[i].data.fd;
            uint32_t epollEvents = eventItems[i].events;
            if (fd == mWakeEventFd) {
                if (epollEvents & EPOLLIN) {
                    awoken();
                } else {
                    printf("Ignoring unexpected epoll events 0x%x on wake event fd.", epollEvents);
                }
            }
        }
    }
    return result;
}

void MessageQueue::awoken() {
    printf("%p ~ awoken\n", this);
    uint64_t counter;
    read(mWakeEventFd, &counter, sizeof(uint64_t));
}

void MessageQueue::wake() {
    printf("%p ~ wake\n", this);
    uint64_t inc = 1;
    ssize_t nWrite = write(mWakeEventFd, &inc, sizeof(uint64_t));
    if (nWrite != sizeof(uint64_t)) {
        //if (errno != EAGAIN) {
           // printf("Could not write wake signal, errno=%d", errno);
        //}
    }
}

void MessageQueue::enqueueMessage(Message* message){
    queueAtFront(message);
    wake();
}

Message* MessageQueue::getNextMessage(){
    pollOnce(0);
    return removeAtTail();
}


























