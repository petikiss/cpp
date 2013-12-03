#include <iostream>

void foo(int x) try
{
    int y = 2;
    throw 1;
}
catch(int e)
{
}

int main(int argc, char** argv)
{
    foo(3);
    return 0;
}
