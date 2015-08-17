// Simple server implelemtation with
// select + fd_set + FS_SET

#include <sys/socket.h>

#include <arpa/inet.h> // inet_addr

#include <iostream>

#include <errno.h>

#include <string.h>
#include <stdio.h>

#include <netdb.h>

#include <unistd.h>   //close


#include <fcntl.h> // file control

// http://www.binarytides.com/multiple-socket-connections-fdset-select-linux/

int main()
{
   int s = socket(PF_INET, SOCK_STREAM, 0); // tcp socket (ip header + tcp header)

   fcntl(s, F_SETFL, fcntl(s, F_GETFL) | O_NONBLOCK);

   if (s < 0)
   {
      std::cout << "Invalid socket descriptor!\n";
   }

   // reusable enabled
   int optval = 1;
   setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

   sockaddr_in sin;
   sin.sin_family = AF_INET;
   sin.sin_port = htons(12345);
   sin.sin_addr.s_addr = inet_addr("127.0.0.1");



   if ( bind(s, reinterpret_cast<sockaddr*>(&sin), sizeof(sockaddr) ) == -1)
   {
      std::cout << "Bind error!\n" << errno << std::endl;
      return 1;
   }
   else
   {
      std::cout << "Bind ok\n";
   }


   if (listen(s, 2) < 0)
   {
      std::cout << "Listen error!\n";
   }
   else
   {
      std::cout << "Listening ("<< s <<") ...\n";
   }

   fd_set master;
   fd_set readfds;
   FD_ZERO(&readfds);
   FD_ZERO(&master);

   FD_SET(s, &master);
   int max = s;
   while(true)
   {
      // because readfds will changed after select()
      readfds = master;

      std::cout << "Waiting in select...\n";
      // timeout=NULL -> block indefinitely
      // when select() returns, readfds will be MODIFIED to indicate which fd are ready
      if ( select(max+1, &readfds, NULL, NULL, NULL) < 0)
      {
         std::cout << "Select error!\n";
      }
      std::cout << "Select end!\n";


      std::cout << "Something happened in socket!\n";
      for(int i = 0; i <=max; i++)
      {
         if (FD_ISSET(i, &readfds))
         {
            // new connection
            if (i == s)
            {
               sockaddr_in newSin; // new connection
               int newSocket;
               socklen_t newLength = sizeof(sockaddr_in); // we have to initialize it!
               newSocket = accept(s, reinterpret_cast<sockaddr*>(&newSin), &newLength);

               if (  newSocket < 0 )
               {
                  std::cout << "Accept failed!\n";
               }
               else
               {
                  std::cout << "New connection(" << newSocket <<") accepted!\n";
                  fcntl(newSocket, F_SETFL, fcntl(s, F_GETFL) | O_NONBLOCK);

                  char str[20]; // ip address
                  inet_ntop(AF_INET,&newSin.sin_addr.s_addr,str,sizeof(str));
                  std::cout << "Remote ip: "  << str << std::endl; // this cannot work, if we not initialize newLengh!
                  std::cout << "Remote port: " << ntohs(newSin.sin_port) << std::endl;

                  char msg[] = "Szia szevasz!\n";
                  send(newSocket, &msg, sizeof(msg),0);

                  FD_SET(newSocket, &master);
                  if (newSocket > max)
                  {
                     max = newSocket;
                     std::cout << "New max socket! " << newSocket << "\n";
                  }
               }
            }
            else // something arrived on an existing connection
            {
               std::cout << "Existing socket (" << i << ") got a message!\n";
               char arrivedData[10];
               int read = 0;
               int db = 0;
               memset(arrivedData, 0, sizeof(arrivedData));

               // recv() block if waiting for data unless socket is unblocking!
               // while (read = recv(i, arrivedData, sizeof(arrivedData), 0) > 0)
               char buf[11]; // terminating zero at the end!
               while ( (read = recv(i, arrivedData, sizeof(arrivedData), 0) ) > 0) // PRECEDENCE!!!!
               {
                  // printf("Darab(%d): %.*s\n", db, (int)read, arrivedData);

                  memset(buf, 0, sizeof(buf));
                  strncpy(buf, arrivedData, read);
                  std::cout << "Darab (" << db <<") arrived (read byte "<< read << "): " << buf << std::endl;
                  memset(arrivedData, 0, sizeof(arrivedData));
                  db++;
               }

               // EOF
               if (read == 0)
               {
                  std::cout << "Client closed the connection!\n";
                  FD_CLR(i, &master);
                  close(i); // without this, socket will reserved until the end of the program!!! -> run out of sockets!!!! /proc/<pid>/fd/
               }

               if (read == -1)
               {
                  if (errno != EAGAIN && errno != EWOULDBLOCK)
                  {
                     std::cout << "Error happened on recv()!\n";
                  }
               }

               std::cout << "Arrived!\n";
            }
         } //  isset
      } // for
      std::cout << "waiting...\n";
   } // while


   return 0;
}
