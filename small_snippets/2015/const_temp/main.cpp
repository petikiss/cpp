#include <iostream>

using namespace std;

int main()
{
    unsigned c = 2004;
    const int &d = c;
    cout << "c erteke: " << c << endl;


    //d = 2012; //Fordíaási hi.
    c = 2012;

    cout << "c erteke: " << c << endl; // kimenet 2012
    cout << "d erteke: " << d << endl; // kimenet 2004
}
