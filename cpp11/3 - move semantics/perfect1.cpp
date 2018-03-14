#include <memory>
#include <iostream>


class Test
{
    int mNumber;
public:
    // Test(int num) : mNumber(num) {std::cout << mNumber << "\n";}
    Test(int& num) : mNumber(num) {std::cout << mNumber << "\n";}
    Test(const Test& rhs) {std::cout << "copy\n";}

    int get() {return mNumber;}
    void inc() {mNumber++;}
};


template <typename T, typename Arg>
std::shared_ptr<T> factory(Arg arg)
{
    return std::shared_ptr<T> (new T(arg));
}


int main()
{
    int number = 6;
    std::shared_ptr<Test> a = factory<Test>(number);


    // std::cout << a.get() << "\n"; // pointer get() function!!!!

    a->inc();
    std::cout << a->get() << "\n";
}
