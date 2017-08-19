#ifndef BOX_EVENT_H
#define BOX_EVENT_H

#include "box_util.h"

#define box_event_type_sock 1
#define box_event_type_timer 2

class box_event //event不仅仅可以是socket还可以是个定时器
{
public:
    box_event(int type);

    int type;
};

class box_event_sock:
        public box_event
{
public:
    box_event_sock(int fd);
    void set_callback(box_read_callback r,box_write_callback w);
    void close();

    void add_ref();
    void del_ref();

public:
    int fd;
    box_read_callback rcbk;
    box_write_callback wcbk;
    int events;
    int cbk_events;
    int ref;//ref count//解决两个客户端使用同一个ev的问题
};

class box_event_timer:
        public box_event
{

};

#endif // BOX_EVENT_H
