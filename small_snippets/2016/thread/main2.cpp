// Creating two single thread

#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* work(void* args)
{
    for(int i = 0; i < 10; ++i)
    {
        sleep(1);
        std::cout << i << std::endl;
    }

    pthread_exit(NULL);
}

void* work2(void* args)
{
    for(int i = 100; i < 110; ++i)
    {
        sleep(1);
        std::cout << i << std::endl;
    }

    pthread_exit(NULL);
}



int main()
{
    pthread_t threadId;

    if (0 != pthread_create(&threadId, NULL, work, NULL))
    {
        std::cout << "Cannot create a new thread!" << std::endl;
    }

    if (0 != pthread_create(&threadId, NULL, work2, NULL))
    {
        std::cout << "Cannot create a new thread!" << std::endl;
    }


    sleep(14);
}
