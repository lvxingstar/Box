#ifndef BOX_H
#define BOX_H

class box_event;
class box_thread;
class box_event_sock;
class box_event_timer;

#include "box_util.h"
#include <stdlib.h>
#include <list>
#include <pthread.h>
#include <semaphore.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>

using namespace std;


class box
{
public:
    box();

    void init(int thread_count);
    void add_socket(int fd,box_read_callback rcbk,box_write_callback wcbk = NULL);
    void run();

    void lock();
    void unlock();

    void add_event(box_event*ev);
    box_event* get_event();//线程拿出来event

    void wait_event();

    void epoll_add(box_event_sock* ev);

private:
    int epollfd;
    list<box_thread*> threads;
    pthread_mutex_t mutex;

    sem_t sem;

    list<box_event*> evs;//消息队列，有消息的时候放到这个消息队列
};

class box_autolock
{
public:
    box_autolock(box*b);
    ~box_autolock();

private:
    box* b;
};

#endif // BOX_H
