#include <iostream>

class A
{
  public:
   virtual ~A() {}
   virtual void print(int i = 2) { std::cout << i*2;}
};


class B : public A
{
  public:
   virtual ~B() {}
   virtual void print(int i = 4) { std::cout << i*8;}
};


int main()
{
   A* a = new B();
   a->print();

   std::cout << "\n";

   dynamic_cast<B*>(a)->print();

   return 0;
}
