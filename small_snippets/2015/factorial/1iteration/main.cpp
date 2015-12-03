#include <iostream>



int main()
{
   int N;
   double factorial = 1;

   std::cout << "Number:";
   std::cin >> N;

   int i = 1;
   while (i <= N)
   {
      factorial *= i;
      i++;
   }

   std::cout << factorial;
   return factorial;
}
