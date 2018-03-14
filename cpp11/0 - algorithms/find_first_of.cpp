
#include <iostream>
#include <algorithm>


int main()
{
    std::string str = "Hello World!";
    std::string needed = "aaw!";


    std::string::iterator it = std::find_first_of(str.begin(), str.end(), needed.begin(), needed.end());


    if (it == str.end())
    {
        std::cout << "Not found any character!";
    }
    else
    {
        std::cout << "We have found a needed character";
    }
}
