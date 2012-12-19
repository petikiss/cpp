// Simple naive try:
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
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        std::cerr << "Socket error!\n";
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);
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

    sockaddr_in incomingAddr;
    socklen_t size = sizeof(sockaddr_in);  // in-out parameter!
    int newFd;
    newFd = accept(sock, (struct sockaddr*)&incomingAddr, &size);

    if (newFd < 0)
    {
        std::cerr << "Accept!\n";
        return 4;
    }

    std::cout << "Incoming address:" << inet_ntoa(incomingAddr.sin_addr) << ":" << ntohs(incomingAddr.sin_port) << "\n";

    while (true)
    {
        char buf[1024];
        memset (buf,0,sizeof(buf));
        int len = recv(newFd, buf, sizeof(buf), 0);
        if (len < 0)
        {
            std::cerr << "recv\n";
            return 5;
        }
        else if (len == 0)
        {
            std::cerr << "Remote  host closed the connection!\n";
            break;
        }
        else
        {
            std::string bufStr(buf);
            std::cout << bufStr;
        }
        sleep(1);
    }

    close(newFd);
    close(sock);
    return 0;
}


