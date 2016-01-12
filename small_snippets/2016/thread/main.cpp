// Creating a single thread

#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* work(void* args)
{
    for(int i = 0; i < 10; ++i)
    {
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


    sleep(1);
}
