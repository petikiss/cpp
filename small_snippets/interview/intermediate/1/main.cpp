#include <iostream>

using namespace std;

int main()
{
    unsigned c = 2004;
    const int &d = c;
    cout << "c erteke: " << c << endl;


    //d = 2012; //Fordítási hiba, ahogy vártam...
    c = 2012; // simán fordul...NEM ahogy vártam :D

    cout << "c erteke: " << c << endl; // kimenet 2012
    cout << "d erteke: " << d << endl; // kimenet 2004
}
