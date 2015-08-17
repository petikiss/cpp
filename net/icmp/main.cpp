#include <iostream>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>

#include <string.h>

unsigned short calcsum(unsigned short *buffer, int length);


struct __attribute__ ((__packed__)) icmp_echo
{
  unsigned char icmp_type;
  unsigned char icmp_code;
  unsigned short icmp_checksum;
  unsigned short icmp_identifier;
  unsigned short icmp_seqnumber;
  char data[10];
};

int main()
{
  int s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  std::cout << s << std::endl;

  sockaddr_in sin;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(12345);
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");


  icmp_echo *icmp;
  icmp->icmp_type = 8;
  icmp->icmp_code = 0;
  icmp->icmp_checksum = 0;
  icmp->icmp_identifier = 0x1131;
  icmp->icmp_seqnumber = 0;
  memset(&icmp->data,0,10);
  memcpy(&icmp->data,"MUHAHAHAH",10);
  icmp->icmp_checksum = calcsum((unsigned short*)icmp, sizeof(icmp_echo)); // checksum szamolas jon a legvegere!


  const char* message = reinterpret_cast<char*>(icmp);

  if (-1 == sendto(s, message, sizeof(icmp_echo), 0,(sockaddr*)&sin, sizeof(sin)))
  {
    std::cout << errno << "Sendto error!\n";
  }
  else
    {
      std::cout << "Packet sent\n";
    }

  return 0;
}


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
