#include <iostream>
#include <sys/time.h>
#include <sys/types.h>

#define STDIN 0

int main()
{
    struct timeval tv;
    fd_set readfds,writefds;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(STDIN,&readfds);
    FD_SET(STDIN,&writefds);

    select(STDIN+1, &readfds, &writefds, NULL, &tv);

    if( FD_ISSET(STDIN,&readfds))
    {
        std::cout << "A key was pressed!\n";
    }
    else
    {
        std::cout << "Timeout!\n";
    }


    return 0;
}
