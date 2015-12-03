#include <iostream>


class B
{
  private:
   int m_b;
};

class A
{
  public:
   A(int a) : m_a(a) {}

   A(const A&) {std::cout << "CopyA\n";}

   void foo(A a, B b)
      {
         a.m_a = 10;
         //b.m_b = 6;
      }

   // what happenes if we remove &
   // what happens if we remove const?
   // what happens if we write void as return value?
   void operator=(const A& rhs)
      {
         // equality???
         std::cout << "Assignment!\n";
         m_a = rhs.m_a;

         // what happenes if we forget "return *this"?
         //  return *this;
      }


   // if we cannot return with reference, a copy constructory will take place
   const A& operator+=(int rhs)
      {
         m_a += rhs;
         return *this;
      }

   int getA()
      {
         return m_a;
      }
  private:
   int m_a;
};



int main()
{
   A a(1);
   A b(2);
   A c(3);

   std::cout << "Original values\n";
   std::cout << "-------------------\n";
   std::cout << "a: " << a.getA() << std::endl;
   std::cout << "b: " << b.getA() << std::endl;
   std::cout << "c: " << c.getA() << std::endl;


   std::cout << "\nAssignment operator\n";
   std::cout << "-------------------\n";
   // a=(b=c); // what happenes in case of this?
   b = c;
   std::cout << "b = c" << std::endl;
   std::cout << "a: " << a.getA() << std::endl;
   std::cout << "b: " << b.getA() << std::endl;


   std::cout << "\n+= operator:\n";
   std::cout << "-------------------\n";

   std::cout << "a+=5\n";
   c = (a+=5);

   std::cout << "a: " << a.getA() << std::endl;
   std::cout << "c: " << c.getA() << std::endl;



}
