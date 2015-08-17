#include <string>
#include <iostream>


int main()
{
   // Because a reference must refer to an object,
   // c++ requires that references be initialized:

   //std::string& rs; // error! References must be initialized

   std::string s("asdf");
   std::string& rs = s;    // okay, rs refers to s
   std::cout << rs;

   //  // Pointers are subject to no such restriction:
   //  std::string *ps;     // uninitialized pointer: valid but risky



   // The fact that there is no such thing as a null reference implies
   // that it can be more efficient to use references than to use pointers.
   // That's because there's no need to test the validity of a reference before using it:
    void printDouble(const double& rd)
    {
       std::cout << rd;         // no need to test rd; it must refer to a double
    }

    //  Pointers, on the other hand, should generally be tested against null:
    void printDouble(const double *pd)
    {
       if (pd) // check for null pointer
       {
          cout << *pd;
       }
    }


}
