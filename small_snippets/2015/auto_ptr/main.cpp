#include <iostream>


template <class T>
class auto_ptr
{
  public:
   auto_ptr(T* t) : data(t) {}

   ~auto_ptr()
   {
      delete data;
   }

  private:
   auto_ptr() {}
   T* data;
};


class A
{
  public:
};


int main()
{
//   A* a = new A();
   auto_ptr<A> i( new A() );

   return 0;
}
