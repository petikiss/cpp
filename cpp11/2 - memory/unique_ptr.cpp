
#include <iostream>
#include <memory>
#include <vector>

class Base
{
    public:
    Base() {std::cout << "Base ctor\n";}
    ~Base() {std::cout << "Base dtor\n";}

    virtual void foo() {std::cout << "I am foo() from Base!\n";}
};


class Derived : public Base
{
public:
    Derived() {std::cout << "Derived ctr\n";}
    ~Derived() {std::cout << "Derived dtor\n";}

    void foo() {std::cout << "I am foo() from Derived!\n";}
};

int main()
{
    std::vector< std::unique_ptr<Base> > v;

    std::unique_ptr<Base> a(new Base());

    //v.push_back(a); // who owns the a?? Will the container destroy it at some point in its lifetime?

    v.push_back(std::move(a));
    // after calling move semantics, a will lose the ownership, and set unique_ptr to NULL
    std::cout << "GET: " << a.get() << "\n"; // null pointer!!!! it is moved to v


    // INHERITANCE
    std::unique_ptr<Base> b(new Derived());
    b->foo();


    // std::unique_ptr<Base> b2(b); // unique_ptr is not copyable




}

