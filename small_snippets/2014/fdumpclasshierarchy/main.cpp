#include <iostream>
using namespace std;


class B
{
  public:
    virtual void g();
  private:
    int m_member;
    char c;
};


class D : public B
{
  public:
    void f();
  private:
    int a;
};


int main()
{
    std::cout << "Size of B: " << sizeof(B) << std::endl;
    std::cout << "Size of D: " << sizeof(D) << std::endl;
}
