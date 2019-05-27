#include <iostream>



/*
// version 1
template <class T>
T getMax(T t1, T t2)
{
   return t1 > t2 ? t1 : t2;
}
*/


// version 2
template <class T>



int main()
{
   // version 1

   std::cout << getMax<int>(5, 6); // OK

   std::cout << getMax<int>(6, 5); // OK

   std::cout << getMax(6, 5); // OK

   std::cout << getMax<int>(5.0, 6.0); // OK

   std::cout << getMax(5.0, 6.0); // OK

   std::cout << std::endl;
   std::cout << getMax<int>(5.0, 5.9); // NOT OK

   std::cout << std::endl;
   std::cout << getMax(5.0, 5.9); // OK

   // std::cout << std::endl;
   // std::cout << getMax(5, 5.9); // Template argument deduction failed


   // version 2

}
