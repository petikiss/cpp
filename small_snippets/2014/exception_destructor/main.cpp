#include <iostream>

class Bad
{
    public:
        ~Bad()
        {
            throw 1;
        }
};

int main()
{
    try
    {
        Bad   bad;
    }
    catch(...)
    {
        std::cout << "Print This" << std::endl;
    }

    try
    {
        Bad   bad; // exception 1
        throw 2;   // exception 2
    }
    catch(...)
    {
        std::cout << "Never print this " << std::endl;
    }
}
