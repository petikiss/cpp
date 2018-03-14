// lambda = anonymous functor type
// [capture_mode] (formal_parameters)mutable throw() -> return_type {body}
// ve can store the lambda to a variable! auto foo = [] ....


#include <iostream>

using namespace std;

int main()
{

    for (int i = 0; i < 10; i++)
    {
        auto f = [i] () {cout << "Value of i is: ", i ;};
        f();
    }

}

/*
[i,j](x, y)->int {abcd}
struct
{
    operator(x,y)
    {
        abcd
    }

private:
    i,j
};
*/

