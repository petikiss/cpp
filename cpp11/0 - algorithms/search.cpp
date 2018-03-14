// found subsequence!


#include <iostream>
#include <algorithm>
#include <vector>


void simple_search()
{
    // basic
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    // what we search exactly
    std::vector<int> v2 = {1,2,3,6};


    std::vector<int>::iterator it = std::search(v.begin(), v.end(), v2.begin(), v2.end());

    if (it != v.end())
    {
        std::cout << "Subsequence found!" << std::endl;
    }
    else
    {
        std::cout << "Subsequence NOT found!" << std::endl;
    }
}



void advanced_search()
{

}


int main()
{
    simple_search();

    advanced_search();
}
