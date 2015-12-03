#include <iostream>

using namespace std;

int main ()
{

int a = 1025;
int *p = &a;
char *q;
char* alma;
int* korte;

q = (char *) p;

cout << "*q erteke egeszben: " << (int)*q << endl; //erteke 1 ahogy vartam
cout << "q címe: " << q << endl;
cout << "p cime: " << p << endl;
cout << "alma cime: " << alma << endl;  // print not the address but the value (char* == string, backward compatibility to C)
cout << "korte cime: " << korte << endl;


}
