#include <iostream>


class Base
{
  public:
   ~Base() {}
   virtual void f()
      {
         a = 9;
      }
  private:
   int a;
};


class Derived : public Base
{
  public:
   ~Derived() { std::cout << "DDDDDD\n";}
   virtual void f()
      {
         b = 10;
      }
  private:
   int a;
   int b;
};


int main()
{
   Base* b = new Derived();

   delete b;

   return 0;
}
