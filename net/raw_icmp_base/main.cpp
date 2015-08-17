#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>  // getuid
#include <sys/types.h>

#include <iostream>

#include <stdlib.h> // malloc
#include <string.h> // memcpy


#include <arpa/inet.h> // inet_addr

#include <errno.h>

struct __attribute__ ((__packed__)) ip_header
{
   unsigned char       ihl:4, version:4;
   unsigned char       dscp_ecn;
   unsigned short int  length; // Total length =  ip_header + icmp_header
   unsigned short int  id;
   unsigned char       offset_high:5, flag2:1, flag1:1, flag0:1;
   unsigned char       offset_low;
   unsigned char       ttl;
   unsigned char       proto;
   unsigned short int  checksum;
   unsigned int        src_ip;
   unsigned int        dst_ip;
};

struct __attribute__ ((__packed__)) icmp_header
{
   unsigned char  type;
   unsigned char  code;
   unsigned short checksum;
   unsigned short id;
   unsigned short seqnumber;
   char data[10];
};



/* calcsum - used to calculate IP and ICMP header checksums using
 * one's compliment of the one's compliment sum of 16 bit words of the header
 */
unsigned short calcsum(unsigned short *buffer, int length)
{
   unsigned long sum;

   // initialize sum to zero and loop until length (in words) is 0
   for (sum=0; length>1; length-=2) // sizeof() returns number of bytes, we're interested in number of words
      sum += *buffer++; // add 1 word of buffer to sum and proceed to the next

   // we may have an extra byte
   if (length==1)
      sum += (char)*buffer;

   sum = (sum >> 16) + (sum & 0xFFFF);  // add high 16 to low 16
   sum += (sum >> 16);          // add carry
   return ~sum;
}



int main()
{
   if (getuid() != 0)
   {
      std::cout << "Sudo rights needed!\n";
      return 1;
   }

   int sd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
   if (sd < 0)
   {
      std::cout << "Socket error!\n";
   }

   int one = 1;
   const int *val = &one;

   // parameters: socket, level what change(IP level), options=header_incl, 1=enabled, sizeof(1)
   if(setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
   {
      std::cout << "setsockopt() error.\n";
      return -1;
   }
   else
   {
      std::cout << "setsockopt() is OK.\n";
   }



   char message[1000];


   ip_header* iph = reinterpret_cast<ip_header*>(message);
   icmp_header* icmph = reinterpret_cast<icmp_header*>(message + sizeof(ip_header));

   // ip header
   memset(iph, 0, sizeof(ip_header));
   iph->ihl = 5;
   iph->version = 4;
   iph->proto = 1;
   iph->length = sizeof(ip_header) + sizeof(icmp_header);
   iph->id = htons(1984);
   iph->ttl = 32;
   iph->flag0 = 0;
   iph->flag1 = 1; // Dont fragment -> 3bit: 010.....
   iph->flag2 = 0;
   iph->offset_high = 0;
   iph->offset_low = 0; // no fragment
   iph->src_ip = inet_addr("127.0.0.1");
   iph->dst_ip = inet_addr("127.0.0.1");
   iph->checksum = calcsum(reinterpret_cast<unsigned short*>(iph), sizeof(ip_header)); // checksum comes last!!!


   // icmp header
   memset(icmph, 0, sizeof(icmp_header));
   icmph->type = 8;
   icmph->code = 0;
   icmph->id = htons(1988);
   icmph->seqnumber = 1;
   icmph->checksum = calcsum(reinterpret_cast<unsigned short*>(icmph), sizeof(icmp_header)); // checksum comes last!!!




   // send the message
   sockaddr_in addr;
   addr.sin_family = AF_INET; // this will be ignored by sendto(), but its present is mandatory!
   addr.sin_addr.s_addr = inet_addr("127.0.0.2"); // this will be ignored by sendto(), but its present is mandatory!


   if (sendto(sd, message, iph->length, 0,
         reinterpret_cast<sockaddr*>(&addr), sizeof(sockaddr)) < 0)
   {
      std::cout << "sendto() error!\n";
      std::cout << "Errno: " << errno;
   }
   else
   {
      std::cout << "ICMP sent\n";
   }


   return 0;
}
