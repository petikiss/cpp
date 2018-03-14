#include "vector.h"

#include <iostream>

int main()
{
    Vector v;


    v.push_back(5);
    v.push_back(50);
    v.push_back(15);
    v.push_back(52);
    v.push_back(0);
    v.push_front(9);


    for(Vector::Iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
