#include <iostream>



class Base
{
  public:
    Base() {std::cout << "Base\n";}
    void kiir() {std::cout << "kiir Base";}
};


class Derived : public Base
{
  public:
    Derived() {std::cout << "Derived\n";}
    void kiir() {std::cout << "kiir Derived";}
};


int main()
{
    Base* d = new Derived();
    d->kiir(); // statikus tipus alapjan kiir (mivel nincs virtual
}
