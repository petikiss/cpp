#include <iostream>




class Base
{
  public:
    Base() { printName(); }
    virtual void printName() { std::cout << "Base\n"; }
};


class Mid : public Base
{
  public:
    Mid() { printName(); }
    void printName() { std::cout << "Mid\n"; }
};


class High : public Mid
{
  public:
    High() { printName(); }
    void printName() { std::cout << "High\n"; }
};










int main()
{
    High h;

    return 0;
}
