#include <iostream>
#include <memory>
//#include <any>

class Client
{
public:
    int m_a;
};

using ClientRef = std::shared_ptr<Client>;


bool iAmWeak(std::weak_ptr<Client> myWeak)
{
    auto mystrong = myWeak.lock();

    if (mystrong)
    {
        mystrong->m_a = 5;
    }
}

//void getAny(const std::any anything)
//{
//    anything.isType;
//}

class MyClass
{
public:
    MyClass(int a) {}
    MyClass() {std::cout << "ctr\n";}
    ~MyClass () {std::cout << "dtr\n";}
};



void foo(int a)
{

}

int main()
{
    std::unique_ptr<MyClass> m ( new MyClass);

    foo(m);
    m->.....



    Client c;

    ClientRef cRef;

    iAmWeak(cRef);


    std::shared_ptr<MyClass> mc = new MyClass(); // ???????
    std::shared_ptr<MyClass> m (new MyClass());

decltype(c) d;

//getAny(std::make_any<Client>(c));

    std::unique_ptr<MyClass[]> (new MyClass[10]);


 //   std::shared_ptr<MyClass[]> (new MyClass[10], [](MyClass* my) {delete[] my;});
    //std::shared_ptr<MyClass> (new MyClass[10], custom_releter_lambda);
}
