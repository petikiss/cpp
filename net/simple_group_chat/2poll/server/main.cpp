#include <sys/socket.h>
//#include <sys/types.h>

#include <iostream>

#include <unistd.h> // getuid

#include <netinet/in.h> // sockaddr_in

#include <arpa/inet.h> // inet_addr - DEPRECATED!

#include <sys/poll.h>

#include <string.h>

// Multi client handling server application
// poll()

// http://www.python4science.eu/multiplex_io.html



int main()
{
   if (getuid() != 0)
   {
      std::cout << "Sudo rights needed!\n";
      return 1;
   }

   //simple TCP socket <=> socket(AF_INET, SOCK_RAW, 5)
   int s = socket(AF_INET, SOCK_STREAM, 0);

   int optval = 1;
   setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

   std::cout << "Server socket: " << s << std::endl;

   sockaddr_in serverAddr;
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(12345);
   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // inet_addr deprecated!

   if ( bind(s, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0 )
   {
      std::cout << "Bind failed!\n";
   }
   else
   {
      std::cout << "Bind ok!\n";
   }

   std::cout << "Listening...\n";

   // backlog: how many incoming connections can be without accept()
   if (listen(s, 10) < 0)
   {
      std::cout << "Listening error!\n";
      return 1;
   }


   sockaddr_in newSocket;
   unsigned int newSocketLen = sizeof(newSocket);
   int newSocketFd;
   if ( (newSocketFd = accept(s, reinterpret_cast<sockaddr*>(&newSocket), &newSocketLen)) < 0 )
   {
      std::cout << "Accept error!\n";
   }
   else
   {
      std::cout << "Connection (" << newSocketFd << ") accepted!\n";
   }


   pollfd ufds[10];

   //std::cout << "Size:" << sizeof(ufds)/sizeof(ufds[0]) << std::endl;

   for (int i = 0; i < sizeof(ufds)/sizeof(*ufds); ++i)
   {
      ufds[i].events = POLLIN | POLLPRI;
      ufds[i].fd = -1;
      std::cout << i  << std::endl;
   }
   ufds[0].fd = s;
   ufds[0].events = POLLIN | POLLPRI;

   ufds[1].fd = newSocketFd;
   ufds[1].events = POLLIN | POLLPRI;

   // Hack: number of conection, use dynamic array instead...
   int max = 2;

   while(true)
   {
      int rv;
      std::cout << "Waiting in poll...\n";
      if ( (rv = poll(ufds, sizeof(ufds)/sizeof(ufds[0]), -1)) == -1 )
      {
         std::cout << "Poll error!\n";
      }

      std::cout << "Poll done!\n";

      if (rv == 0)
      {
         std::cout << "No data arrived on poll!\n";
      }
      else
      {
         for(int i = 0; i < sizeof(ufds)/sizeof(ufds[0]); i++)
         {
            if (ufds[i].revents & POLLIN)
            {
               if (ufds[i].fd == s)
               {
                  std::cout << "New connection accepted!\n";
                  sockaddr_in newSocketSin;
                  unsigned int newSocketSinLen = sizeof(newSocketSin);
                  int newSocketFd;
                  newSocketFd = accept(s, reinterpret_cast<sockaddr*>(&newSocketSin), &newSocketSinLen);
                  ufds[max].fd = newSocketFd;
                  max++;
               }
               else
               {
                  std::cout << "Recived data from existing socket!\n";
                  char readData[10];
                  unsigned int readDataLen = 10;
                  int num = 0;
                  while ( ( num = recv(ufds[i].fd, readData, readDataLen, 0)) > 0)
                  {
                     char data[11];
                     memset(data, 0, 11);
                     memcpy(data, readData, num);
                     std::cout << "Data peace: " << data << std::endl;
                  }

                  // client closed the connection (EOF)
                  if (num == 0)
                  {
                     std::cout << "Client closed the connection!\n";
                     close(ufds[i].fd);

                     // Nicer solution is using a dynamic array...
                     ufds[i].fd = -1;
                  }

                  if (num < 0)
                  {
                     std::cout << "Read error!\n";
                  }
               }
            }
         } // for
      } // else

   } // while

   return 0;
}
