#include <iostream>


class Base
{
  public:
    Base() {std::cout << "Base()\n";}
    ~Base() {std::cout << "~Base()\n";} // virtual???
    Base(const Base&) {std::cout << "CopyB\n";}
};


class Derived : public Base
{
  public:
    Derived() {std::cout << "Derived()\n";}
    ~Derived() {std::cout << "~Derived()\n";}
    Derived(const Base&) {std::cout << "CopyDerived\n";}

    Base* create(Base g)
    {
        return new Derived();
    }
};


int main()
{
    Derived d;
    // Base b;
    // Base* g = d.create(b);
    Base* g = d.create(Base()); // copy elision
    delete g;

    return 0;
}

