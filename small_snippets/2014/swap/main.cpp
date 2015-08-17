// xor swap algorithm
#include <iostream>


int main()
{
    int x = 8;
    int y = 7;

    x = x^y; // XOR
    y = x^y;
    x = x^y;

    std::cout << "x:" << x << " y:" << y <<std::endl;

}
