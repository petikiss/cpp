// Template method design pattern
// http://www.gotw.ca/publications/mill18.htm

#include <iostream>

class B
{
  public:

   // the skeleton of an algorithm in a base class "template method"
   void execute()
      {
         printPrivateBase1();
         printPrivateBase2();
      }
  private:
   virtual void printPrivateBase1() = 0; // abstract method, mandatory to implement!
   virtual void printPrivateBase2() = 0; // abstract method, mandatory to implement!
};


class D : public B
{
  public:
   void printPrivateBase1()
      {
         std::cout << "Concrate implementation in derived class!\n";
      }

   void printPrivateBase2()
      {
         std::cout << "Concrate implementation in derived class!\n";
      }

   void printDerived()
      {
         execute();
      }
  private:
};



int main()
{
   D d;
   d.printDerived();
}


