#include <iostream>


template <class T>
class shared_ptr
{
    T* _t = nullptr;
public:
    // explicit shared_ptr(T* t) { std::cout << "ctr\n"; _t = t;}
    shared_ptr(T* t) { std::cout << "ctr\n"; _t = t;}

    operator int*() { std::cout << "operator int*()\n"; return _t;} // implicit type conversion
};



void foo(shared_ptr<int> tmp)
{
    std::cout << "foo()";
}


int main()
{
    //shared_ptr<int> t = new int();
    int t2 = 6;

    foo(&t2); // constructor
    shared_ptr<int> tmp = &t2; // constructor
    shared_ptr<int> tmp2 = new int; // constructor

    int* t = tmp; // tmp.operator int*() -> implicit type conversion operator
}
