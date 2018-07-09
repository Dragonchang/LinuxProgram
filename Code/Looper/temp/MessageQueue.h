#ifndef H_MESSAGEQUEUE
#define H_MESSAGEQUEUE
#include "Message.h"
#include <fcntl.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>
#include<stdio.h>
#include<unistd.h>
 #include <string.h>
/*
保存消息实体,looper会在该对象上等待消息进行处理;
looper会发送相应的消息到该对象中.
++++++++++++++++++++++++++++++++++++++
+ 
+
++++++++++++++++++++++++++++++++++++++
*/
class Message;
class MessageQueue {
public:
    MessageQueue();
    virtual ~MessageQueue();
    void queueAtFront(Message* message);
    Message* removeAtTail();

    int pollOnce(int timeoutMillis); //主线程在messagequeue中等待消息事件时的睡眠函数
    void wake(); //消息发送到messageueue的wake函数
    void enqueueMessage(Message* message);
    Message *getNextMessage();
    enum {
        /**
         * Result from Looper_pollOnce() and Looper_pollAll():
         * The poll was awoken using wake() before the timeout expired
         * and no callbacks were executed and no other file descriptors were ready.
         */
        POLL_WAKE = -1,

        /**
         * Result from Looper_pollOnce() and Looper_pollAll():
         * One or more callbacks were executed.
         */
        POLL_CALLBACK = -2,

        /**
         * Result from Looper_pollOnce() and Looper_pollAll():
         * The timeout expired.
         */
        POLL_TIMEOUT = -3,

        /**
         * Result from Looper_pollOnce() and Looper_pollAll():
         * An error occurred.
         */
        POLL_ERROR = -4,
    };
    /**
     * Flags for file descriptor events that a looper can monitor.
     *
     * These flag bits can be combined to monitor multiple events at once.
     */
    enum {
        /**
         * The file descriptor is available for read operations.
         */
        EVENT_INPUT = 1 << 0,

        /**
         * The file descriptor is available for write operations.
         */
        EVENT_OUTPUT = 1 << 1,

        /**
         * The file descriptor has encountered an error condition.
         *
         * The looper always sends notifications about errors; it is not necessary
         * to specify this event flag in the requested event set.
         */
        EVENT_ERROR = 1 << 2,

        /**
         * The file descriptor was hung up.
         * For example, indicates that the remote end of a pipe or socket was closed.
         *
         * The looper always sends notifications about hangups; it is not necessary
         * to specify this event flag in the requested event set.
         */
        EVENT_HANGUP = 1 << 3,

        /**
         * The file descriptor is invalid.
         * For example, the file descriptor was closed prematurely.
         *
         * The looper always sends notifications about invalid file descriptors; it is not necessary
         * to specify this event flag in the requested event set.
         */
        EVENT_INVALID = 1 << 4,
    };

private:
    Message* mHead;
    Message* mTail;
    int mWakeEventFd; //消息发送时唤醒fd
    int mEpollFd;  //主线程等待消息时waite的fd
    void awoken();
    void buildEpollLocked();
};
#endif
