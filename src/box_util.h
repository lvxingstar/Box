#ifndef BOX_UTIL_H
#define BOX_UTIL_H
//这里是用来封装socket函数的类（工具类）

#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

class box_event;
class box_event_sock;

typedef void(*box_read_callback)(box_event_sock* );
typedef void(*box_write_callback)(box_event_sock* );
void box_set_nonblock(int fd);
int box_cretae_server(uint16_t port,const char* ip="0.0.0.0");

#define box_err printf
#define box_debug printf

#endif // BOX_UTIL_H
