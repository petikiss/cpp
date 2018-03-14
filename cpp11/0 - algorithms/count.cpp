// used algorithms: count, count_if

#include <iostream>
#include <algorithm>


bool isOdd(int i) {return i%2==1 ;}



int main()
{
    std::vector<int> v = {1,2,3,4,5,1,2,1,1};

    // value
    std::cout << std::count(v.begin(), v.end(), 1);

    std::cout << std::endl;

    // function pointer (functor also ok)
    std::cout << std::count_if(v.begin(), v.end(), isOdd);

    std::cout << std::endl;

    // lambda expression
    std::cout << std::count_if(v.begin(), v.end(), [](int i) {return i%2 == 1;});


}
