#include <sys/socket.h>
#include <sys/types.h>


#include <netinet/in.h>

#include <arpa/inet.h>

#include <iostream>
#include <errno.h>

#include <string.h>

// The IP header's structure
struct ipheader
{
   unsigned char      iph_ihl:4, iph_ver:4; // ihl: 32bit words in header (5x32=160bit=20byte)
     unsigned char      iph_tos;
   unsigned short int iph_len; // total length (iplength+data -> min 20byte)
     unsigned short int iph_ident;
     unsigned char      iph_flag;
     unsigned short int iph_offset;
     unsigned char      iph_ttl;
     unsigned char      iph_protocol;
     unsigned short int iph_chksum;
     unsigned int       iph_sourceip;
     unsigned int       iph_destip;
};




int main()
{
   int s = socket(AF_INET, SOCK_RAW, 1); // -> teljes ipv4 header + Protokol=1, majd erre tesszuk a data reszt
   if (s < 0)
   {
      std::cout << "Error socket() ("<< errno << ")\n";
      return -1;
   }

   sockaddr_in in;

   in.sin_family = AF_INET;
   in.sin_port = htons(8080);
   in.sin_addr.s_addr = inet_addr("127.0.0.1");

   // Inform the kernel do not fill up the packet structure. we will build our own...
   int one = 1;
   const int *val = &one;

   // if(setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
   // {
   //    std::cout << ("setsockopt() error");
   //    return -1;
   // }
   // else
   // {
   //    std::cout << ("setsockopt() is OK.\n");
   // }

   // ipheader* iph;
   // iph->iph_ver = 4;
   // iph->iph_ihl = 5;
   // iph->iph_tos = 0;
   // iph->iph_len = 20;
   // iph->iph_protocol = 1;
   // iph->iph_chksum = 0;
   // iph->iph_sourceip = inet_addr("127.0.0.1");
   // iph->iph_destip =  inet_addr("127.0.0.1");

   char buff[8192];
   memset(buff, 0, 8192);

//   iph = reinterpret_cast<ipheader*>(buff);

//   if(sendto(s, buff, sizeof(*iph), 0, (sockaddr*)&in, sizeof(in) ) < 0)
   if(sendto(s, "DATA PART", 10, 0, (sockaddr*)&in, sizeof(in) ) < 0)
   {
      std::cout << "Error send (" << errno << ")\n";
   }

   return 0;
}
