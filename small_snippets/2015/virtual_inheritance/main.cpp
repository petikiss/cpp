// http://www.phpcompiler.org/articles/virtualinheritance.html


#include <iostream>

class Top
{
public:
   int a;
};

class Left : public Top
{
public:
   int b;
};

class Right : public Top
{
public:
   int c;
};

class Bottom : public Left, public Right
{
public:
   int d;
};




int main()
{
//   Bottom b; // OK

   Left* left = new Left();
   Top* top = left; // upcast ok

   std::cout << "Left: " << left << " Top: " << top << std::endl;

   Bottom* bottom = new Bottom();
   left = bottom; // OK
   std::cout << "Left: " << left << " Bottom: " << bottom << std::endl;

   bottom = new Bottom();
   Right* right = bottom; // OK
   std::cout << "Right: " << right << " Bottom: " << bottom << std::endl; // different mem address!


//   Bottom* bottom = new Bottom();
//   Top* top = bottom;
}

