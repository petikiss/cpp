// Factorial calculation with recursion

#include <iostream>


int factor(int f)
{
    if (f==0 || f==1)
    {
        return 1;
    }
    int prev = factor(f-1);
    return prev*f;
}



int main()
{
    int fac=7;
    std::cout << fac << "!:" << factor(fac);
}
