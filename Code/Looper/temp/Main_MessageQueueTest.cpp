#include"Handler.h"
#include"Message.h"
#include"NThread.h"
int main() {
    void *tret;
    NThread thread;
    Handler handler(thread.getLooper());
    Message message(2);
    handler.sendMessage(&message);
    //pthread_join(thread.getTid(),tret);
    return 0;
}
