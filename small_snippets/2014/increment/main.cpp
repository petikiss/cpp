#include <iostream>


int main()
{
    int i = 0;
    int k = 0;
    // k = (i++)++; // hiba -> T operator+(int)
    k = ++(++i);    // ok -> T& operator+()
    k = ++i++;
    std::cout << k << std::endl;

    return 0;
}

