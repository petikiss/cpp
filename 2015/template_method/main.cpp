// Template method design pattern

#include <iostream>

class B
{
  public:
   void printBase() { printPrivateBase(); }
  private:
   virtual void printPrivateBase() = 0; // abstract method, mandatory to implement!
};


class D : public B
{
  public:
   void printPrivateBase()
      {
         std::cout << "Concrate implementation in derived class!\n";
      }

   void printDerived()
      {
         printBase();
      }
  private:
};



int main()
{
   D d;
   d.printDerived();
}


