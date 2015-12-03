#include <iostream>

using namespace std;

int main ()
{

int a[3];

a[0] = 5;
a[1] = 2;
a[2] = -4;

int *p = &(a[0]);

// A harmadik elem erteke
cout  << "*(++(++q)) erteke: " << *(++(++p)) << endl;


// A harmadik elem erteke
//cout  << "*((++q)++) erteke: " << *((++q)++) << endl;


// a[3] = 1;
// a[4] = 1;
// a[5] = 1;

// cout << a[5]  << endl; // megkapjuk az 1 erteket

// *(a + 5) = 2;

// cout << a[5]  << endl; // megkapjuk a 2 erteket
// //...

}
