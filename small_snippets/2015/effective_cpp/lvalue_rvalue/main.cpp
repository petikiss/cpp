// http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c

int foo()
{
   return 2;
}


int& foo2()
{
   return 2;
}


int main()
{
   // foo() = 2; // lvalue required as left operand of assignment

   foo2(); // invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'


   return 0;
}
