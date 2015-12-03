#include <iostream>
#include <string>
#include <fstream>

#include "Bencoder.hh"

std::string fileName = "archlinux-2015.11.01-dual.iso.torrent";

std::string testString = "d9:publisher3:bob17:publisher-webpage15:www.example.com18:publisher.location4:homee";

int main()
{
   std::ifstream inp;

   inp.open(fileName.c_str());

   if (inp.fail())
   {
      std::cout << "File open error!\n";
      return 1;
   }


//   while(!inp.eof())
   {
      std::string str;
      inp >> str;
//      std::cout << str;
      std::cout << "Test string: \n" << testString;
      Bencoder bencoder;
      bencoder.encode(testString);
      std::cout << std::endl << bencoder.getOutput();
      std::cout << "\n";
   }
}
