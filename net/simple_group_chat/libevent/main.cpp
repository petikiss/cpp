
#include <iostream>

#include <sys/socket.h>

#include <netinet/in.h> // sockaddr_in

#include <arpa/inet.h> // inet_addr


int main()
{
   int s = socket(AF_INET, SOCK_STREAM, 0);

   int optval = 1;
   setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

   sockaddr_in sin;
   sin.sin_family = AF_INET;
   sin.sin_port = htons(12345);
   sin.sin_addr.s_addr = inet_addr("127.0.0.1");

   if (bind(s, reinterpret_cast<sockaddr*>(&sin), sizeof(sockaddr) ) < 0)
   {
      std::cout << "Bind error!\n";
      return 1;
   }

   if ( listen(s, 10) < 0)
   {
      std::cout << "Listening error!\n";
      return 1;
   }
   else
   {
      std::cout << "Listening...\n";
   }


   sockaddr_in newSin;
   unsigned int newSinLen;
   if ( accept(s, reinterpret_cast<sockaddr*>(&newSin), &newSinLen) < 0)
   {
      std::cout << "Error while accepting connection!\n";
      return 1;
   }
   std::cout << "Connection accepted!\n";


   // server functionality
   // while (true)
   // {
   // } // while


}
