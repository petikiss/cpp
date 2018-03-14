#include <iostream>
#include <vector>


class HasCopyMoveClass
{
    public:
        HasCopyMoveClass()
        {
            std::cout << "ctr\n";
        }

        ~HasCopyMoveClass()
        {
            std::cout << "dtr\n";
        }

        HasCopyMoveClass(const HasCopyMoveClass& rhs)
        {
            std::cout << "copy\n";
        }

        HasCopyMoveClass(HasCopyMoveClass&& rhs)
        {
            std::cout << "move\n";
        }


};

template<class T>
class Vector {
    std::vector<T> _impl;
public:
    void add(T value) {
         _impl.push_back(value);
    }
};


int main()
{
    Vector<HasCopyMoveClass> v;

    HasCopyMoveClass a;
    //HasCopyMoveClass b;

    v.add(a);
}
