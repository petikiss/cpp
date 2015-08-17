#include <iostream>  // TODO: DELETE IT!
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h> // sockaddr_in
#include <arpa/inet.h> // inet_pton


#include <errno.h> // perror
#include <stdio.h> // perror

int main()
{
    int sockFd = socket(PF_INET,SOCK_STREAM,0);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("10.144.1.10");
    addr.sin_port = htons(8080);



     if ( 0 != connect(sockFd, (struct sockaddr*)&addr, sizeof(addr)))
     {
         perror("Marci connect");
         // std::string str;
         // str << strerror(errno);
         // std::cout << str;
     }
     else
     {
         std::cout << "Connected\n";
     }

     std::string connect = "CONNECT ssh.github.com:443 HTTP/1.0";
     int s1 = send(sockFd, connect.c_str(), connect.size(),0);
     std::cout << s1 << "\n";
     int s2 = send(sockFd,"\n\n",2,0);
     std::cout << s2 << "\n";

     char buf[1024];
     memset (buf, 0, 1024);
     int s3 = recv (sockFd, buf, 1024, 0);
     std::cout << s3 << "\n";

     std::string bufStr(buf);
     std::cout << "Server ansvered: " << bufStr << "|\n";

    return 0;
}
