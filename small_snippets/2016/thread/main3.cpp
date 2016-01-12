// Creating a single thread, and add some attritube, and a parameter

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

struct ThreadData
{
    ThreadData() : message("Szia"), data(5)  {}
    std::string message;
    int data;
};


void* work(void* args)
{
    ThreadData data = *((ThreadData*)(args));

    pthread_t selfThreadId = pthread_self();
    printf("%08x\n", selfThreadId);
    std::cout << std::hex << selfThreadId << std::endl;
    
    std::cout << data.message << std::endl;
    for(int i = 0; i < 10; ++i)
    {
        std::cout << i << std::endl;
    }

    pthread_exit(NULL);
}



int main()
{
    pthread_t threadId;
    ThreadData data;
    pthread_attr_t attr;

    sched_param schedparam;
    schedparam.sched_priority = 3;

    pthread_attr_init(&attr);
//    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_setschedparam(&attr, &schedparam);

    int err = 0;
    if (0 != (err = pthread_create(&threadId, &attr, work, (void*)(&data))))
    {
        std::cout << "Cannot create a new thread! (" << err << ")" << std::endl;
    }

    pthread_attr_destroy(&attr);
    sleep(1);
}



