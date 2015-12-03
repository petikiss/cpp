#include <iostream>

// -fdump-class-hierarchy

using namespace std;

// cc**iiiissc*iiiicc**

struct C
{
   int c;
};

struct A
{
   char a; // 1
   char b; // 1
   int c;  // 4
   short d; // 2
   char e; // 1
   int g; // 4
   char h; // 1
   C i;
};

// cc**iiiiddc*ssssiiiic***
struct almafa
{
  char a;
  char b;
  int c;
  short int d;
  char e;
  std::string f;
  int g;
  char h;
};



int main()
{
   std::cout << "A:" << sizeof(A);
   int tomb[5];
  int tombUtaniElem = 10;

  //cout << tomb[5]; // kiirtad a "tombUtaniElem" erteket :)
  tomb[5] = 30; // atirdat a "tombUtaniElem" erteket :)
  cout << "tombUtaniElem: " << tombUtaniElem;
}
