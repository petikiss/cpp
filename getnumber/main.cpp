#include <iostream>



class BASE
{
  public:
    BASE() {std::cout << "BC" << std::endl;}
    BASE(const BASE&) {std::cout << "BY" << std::endl;}
    virtual ~BASE() {std::cout << "BD" << std::endl;}
};

class DERIVED : public BASE
{
  public:
    DERIVED() {std::cout << "DC" << std::endl;}
    DERIVED(const DERIVED&) {std::cout << "DY" << std::endl;}
    ~DERIVED() {std::cout << "DD" << std::endl;}

    BASE* func(BASE b)
        {
            return new DERIVED();
        }
};


int main()
{
    std::cout << std::endl;
    DERIVED d;
    // BASE g;
    BASE* b = d.func(BASE());
    delete b;

    return 0;
}
