#include <iostream>
#include <vector>

using namespace std;

class A
{

public:
   A() { cout << "ctor: " << this << endl;}
   A(const A&) { cout << "cctor: " << this << endl;}

   ~A() {cout << "dtor: " << this << endl;}
};

int main()
{
   int i = 0;
   vector<A> tomb;
   tomb.reserve(3);

   for(int i = 0; i < 3; ++i)
   {
      cout << endl;
      A valami;
      cout << "push: ";

      tomb.push_back(valami);
//      cout << "push_back utan" << endl;

   }
   
   tomb.reserve(16);
   cout << "end\n\n\n";
   
   cout << "Kapasziti:" <<  tomb.capacity() << endl;
   return 0;
}
