/*
#include <iostream>



class Marci
{
    int size;
    int* array;
public:
    Marci() { std::cout << "ctr"; }

    Marci(const Marci& rhs)
    {
            std::cout << "copy";

        size = rhs.size;
        array = new int[size];

        for(int i = 0; i < size; ++i) { array[i] = rhs.array[i]; }


    }


    Marci(Marci&& rhs)
    {
        std::cout << "ATTILA EZ BEZONY MOVE!!!!!!!!! EZ MAR CPP1111111";
    }

};


void foo(Marci m)
{

}

Marci createMarci()
{
    Marci m;
    return m;
}

int main()
{
    // Marci m;
    // foo(m);


    foo(createMarci());
}

*/

#include <iostream>

class X
{
public:
    X() {std::cout << "ctr\n";}

    ~X() {std::cout << "~ctr\n";}

    X(X&)
    {
        std::cout << "copy\n";
    }

    X(X&& rhs)
    {
//        size = rhs.size;
  //      array = rhs.array;
    //    rhs.array = nullptr;

      //  rhs.size = 0;// ????

        std::cout << "move\n";
    }
};



void foo(X& x) { std::cout << ":(\n"; }; // lvalue reference overload
void foo(X&& x) {std::cout << ":)\n";}; // rvalue reference overload



X foobar()
{
    X x;
    return x;
}


int main()
{

X x;

foo(std::move(x)); // argument is lvalue: calls foo(X&)
// foo(foobar()); // argument is rvalue: calls foo(X&&)

int a = 0;

}
