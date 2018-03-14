#include <iostream>
#include <vector>

class A
{
public:
    A() : _v({1,2,3,4,5,6}) {}
    std::vector<int>::iterator begin() { return _v.begin(); }
    std::vector<int>::iterator end() {return _v.end(); }
private:
    std::vector<int> _v;
};

A foo()
{
    A a;
    return a;
}

int main()
{
    {
        int a = 6;
        auto b = a;

        std::cout << b << std::endl;
    }

    {
        auto a = 6;
        std::vector<int> v = {1,2,3,a}; // initializr list

        // attr(optional) for ( range_declaration : range_expression ) loop_statement
        for(int i:v)
        {
            std::cout << i << ",";
        }

        std::cout << std::endl;
    }


    {
        // Warning! ill formed expression
        A a;
        for(int i : a)
        {
            std::cout << i << std::endl;
        }


    }
}
