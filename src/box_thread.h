#ifndef BOX_THREAD_H
#define BOX_THREAD_H
//#include "box.h"//这个地方发生了循环包含，重复包含 使用前置声明的方法
//在这个头文件中，我们只是使用到了box的指针，或者变量，在这里我们前置声明之后
//就是只知道有这个类，但是并不知道这个类中有什么，也不需要知道，而在要用到里面东西的时候，再include。
#include <pthread.h>
class box;

class box_thread
{
public:
    box_thread(box* b);

    void run();

private:
    static void* thread_func(void* ptr);
    box* b;
    pthread_t tid;
};

#endif // BOX_THREAD_H
