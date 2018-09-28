#include <iostream>

// Exercise: get() is mandatory!


class Base
{
public:
    Base() {}
    ~Base() {}
//    virtual int get() {};
};



class D1 : public Base
{
public:
    D1() : mInt(1994) {}
    int get() {return mInt;}
private:
    int mInt;
};


class D2 : public Base
{
public:
    D2() : mStr("ok") {}
    std::string get() {return mStr;}
private:
    std::string mStr;
};


int main()
{
    D2* b = new D2();

    std::cout << b->get();
}