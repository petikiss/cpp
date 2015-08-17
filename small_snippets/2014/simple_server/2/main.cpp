// 2 try:
// Only 1 connection
// Accept block the whole process
// Recv is handling only ~1K data
// Sleep in while...

#include <iostream> // TODO: delete this

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h> // inet_pton

#include <unistd.h> // sleep

#include <string>
#include <string.h>

int main()
{
    int sock = socket(PF_INET, SOCK_STREAM, 0); // listener socket
    if (sock < 0)
    {
        std::cerr << "Socket error!\n";
        return 1;
    }

    // lose "address already in use" error message
    int yes = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1",&serverAddr.sin_addr);

    if (bind(sock, (struct sockaddr*)&serverAddr, sizeof(sockaddr_in)) < 0)
    {
        std::cerr << "Bind!\n";
        return 2;
    }

    if (listen(sock, 3) < 0) // max 2 connection (backlog)
    {
        std::cerr << "Listen!\n";
        return 3;
    }

    int maxSocketNum = sock;
    fd_set master;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_ZERO(&master);
    FD_SET(sock, &master);

    // main loop
    while(true)
    {
        rfds = master;
        timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if (-1 == select(maxSocketNum+1, &rfds, NULL, NULL, &tv))
        {
            std::cerr << "Select\n";
        }

        for (int i = 3; i < maxSocketNum+1; i++)
        {
            // if there is a socket with readable data
            if (FD_ISSET(i, &rfds))
            {
                //we have a new incoming connection
                if(i == sock)
                {
                    sockaddr_in newAddr;
                    socklen_t size = sizeof(sockaddr_in);
                    int newFd = accept(sock, (struct sockaddr*)&newAddr, &size);
                    if (newFd == -1)
                    {
                        std::cerr << "Accept\n";
                    }
                    maxSocketNum = (newFd > maxSocketNum) ?  newFd : maxSocketNum;
                    FD_SET(newFd, &master);
                    std::cout << "New connection established! (" << newFd << ")" << std::endl;
                }
                else // server got some data
                {
                    char buf[1024];
                    memset(buf, 0, sizeof(buf));
                    int len = recv(i,buf, sizeof(buf),0);
                    if (len < 0)
                    {
                        std::cerr << "Recv\n";
                        // Maybe: FD_CLR() or exit() ...
                    }
                    else if (len == 0)
                    {
                        std::cout << "Remote client closed the connection!\n";
                        FD_CLR(i, &master);
                    }
                    else
                    {
                        std::string bufStr(buf);
                        std::cout << "Socket "<< i << " recived:" << bufStr << std::endl;
                    }
                }
            }
        } // for
    } // while(true)

    return 0;
}


