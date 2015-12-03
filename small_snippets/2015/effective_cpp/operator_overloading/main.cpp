#include <iostream>
#include <string.h>


bool operator&&(bool a, bool b)
{
   std::cout << "Overloaded operator!\n";
}


int main()
{
   const char* p = "Hello World\n";

   if (p != 0 && strlen(p) > 10 )
   {
      std::cout << "I am long!\n";
   }
}


