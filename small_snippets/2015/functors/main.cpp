#include <iostream>



class Functor
{
  public:
   int operator()(int param1, int param2)
      {
         return param1 + param2;
      }
  private:
};




int main()
{
   Functor f;

   int result = f(4,5);

   std::cout << result << std::endl;
   return 0;
}
