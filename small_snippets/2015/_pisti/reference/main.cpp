#include <iostream>

using namespace std;



//  int c = 8;
// const int& a = c;
//  std::cout << a;
//  c = 9;
//  std::cout << a;

// int main ()
// {
//    unsigned c = 2004;
//    const int &d = c;
//    cout << "Memoria1: " << &c << " " << &d << std::endl;
//    c = 5;
//    cout << "Data1: " << c << " " << d << std::endl;



// }


int main ()
{
    long a = 0x22025656;
    short *m = new(&a) short;
    cout << "*m erteke: " << hex << *m << endl; // kimenet: 5656
return 0;
}
