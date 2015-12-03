#include "Bencoder.hh"

#include <assert.h>
#include <iostream>
#include <sstream>


bool
Bencoder::isNumber(char ch) const
{
   if ( ch == '0' || ch == '1' || ch == '2' || ch == '3' ||
        ch == '4' || ch == '5' || ch == '6' || ch == '7' ||
      ch == '8' || ch == '9')
   {
      return true;
   }

   return false;
}

int
Bencoder::toInteger(std::string str) const
{
   std::stringstream sstream;

   sstream << str;
   int result;
   sstream >> result;
   return result;
}

Bencoder::Bencoder() : mIndex(0)
{
}

void
Bencoder::parseDirectory(std::string str)
{
   assert(str[mIndex] == 'd');

   std::cout << "\nDirectory parse\n";

   mOutput += "D{\n";
   mIndex++; // eat 'd'
   encode(str);
   mOutput += "}D\n";
   mIndex++; // ead 'e'
}

void
Bencoder::encode(std::string str)
{
   while (mIndex != str.length())
   {
      // std::cout << "Length: " << str.length() << " index: " << mIndex << std::endl;
      switch(str[mIndex])
      {
         case 'd':
         {
            parseDirectory(str);
            break;
         }
         default:
         {
            if (isNumber(str[mIndex]))
            {
               parseString(str);
            }
         }
      }
   } // while
}


void
Bencoder::parseString(std::string str)
{
   assert(isNumber(str[mIndex]));

   std::string length = "";
   while (str[mIndex] != ':')
   {
      length += str[mIndex];
      mIndex++;
   }
   mIndex++; // ':'

   // std::cout << "Length of string:" << length << std::endl;

   mOutput += length;
   mOutput += "s : ";
   std::cout << str.substr(mIndex, toInteger(length));
   mOutput += str.substr(mIndex, toInteger(length));
   mOutput += "\n";

   mIndex += toInteger(length);
}


const std::string&
Bencoder::getOutput() const
{
   std::cout << "Final result:\n";
   return mOutput;
}
