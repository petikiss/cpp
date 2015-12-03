#include <iostream>




double factorial(int N)
{
   if (N == 0) return 1;


   return factorial(N-1)*N;
}


int main()
{
   std::cout << factorial(3);

   return 0;
}
