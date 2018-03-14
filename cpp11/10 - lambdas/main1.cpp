// lambda = anonymous functor type
// [capture_mode] (formal_parameters)mutable throw() -> return_type {body}


#include <iostream>

using namespace std;

int main()
{

auto func = [] () {cout  << "Hello world!"; };
func();


return 0;
}
