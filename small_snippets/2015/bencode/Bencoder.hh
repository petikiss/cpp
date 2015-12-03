#ifndef BENCODER_HH
#define BENCODER_HH

#include <string>


class Bencoder
{
 public:
   Bencoder();
   void encode(std::string str);
   void parseString(std::string str);
   void parseDirectory(std::string str);
   const std::string& getOutput() const;
 private:
   bool isNumber(char ch) const;
   int  toInteger(std::string) const;

   int mIndex;
   std::string mOutput;
};



#endif
