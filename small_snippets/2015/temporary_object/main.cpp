// temporary object -> implitit cast (const vs non-const)

// return value optimalisation

// copy elision

#include <iostream>

class Integer
{
  public:
   Integer() {std::cout << "normal constructor\n";}
   ~Integer() {std::cout << "destructor\n";}
   /*explicit*/ Integer(int i) {std::cout << "convert\n";}

   Integer(const Integer& i) { std::cout << "copy\n";}
   Integer& operator=(const Integer& rhs) {std::cout << "op=\n";}
};


void foo(Integer i) // OK - use explicit to prevent this
{

}


void foo2(Integer& i) // NOK - non-const temporary with reference??
{
}

void foo3(const Integer& i) // OK - const temporary, will not change
{
}


Integer non_rvo()
{
   Integer temp;  // named variable -> dont optimalize
   Integer t1;
   Integer t2;
   temp = t1;
   return temp;
}

Integer rvo()
{
   return Integer();
}


int main()
{

   int i;

   // foo(i); // OK
   // foo2(i); // NOK
   //foo3(i); // OK

   Integer j1 = non_rvo();
   //Integer j2 = rvo();  // return value optimalization
}
