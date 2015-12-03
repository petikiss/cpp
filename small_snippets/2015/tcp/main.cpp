#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

unsigned short csum(unsigned short *buf, int nwords)
{       //
        unsigned long sum;
        for(sum=0; nwords>0; nwords--)
           sum += *buf++;

        sum = (sum >> 16) + (sum &0xffff);
        sum += (sum >> 16);
        return (unsigned short)(~sum);
}

 struct ipheader
 {
 unsigned char      iph_ihl:5, iph_ver:4;
 unsigned char      iph_tos;
 unsigned short int iph_len;
 unsigned short int iph_ident;
 unsigned char      iph_flag;
 unsigned short int iph_offset;
 unsigned char      iph_ttl;
 unsigned char      iph_protocol;
 unsigned short int iph_chksum;
 unsigned int       iph_sourceip;
 unsigned int       iph_destip;
};


 // UDP header's structure

struct udpheader
{
 unsigned short int udph_srcport;
 unsigned short int udph_destport;
 unsigned short int udph_len;
 unsigned short int udph_chksum;
};


int main()
{
   int s = socket(AF_INET, SOCK_RAW, 0);


   sockaddr_in addr;

   addr.sin_family = AF_INET;
   addr.sin_port = htons(11111);
   addr.sin_addr.addr = "";


   const char* message = "Szia!";
   sendto(s, message, 6, 0, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));

}
