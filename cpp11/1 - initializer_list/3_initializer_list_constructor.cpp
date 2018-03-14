#include <iostream>
#include <initializer_list>

// http://www.learncpp.com/cpp-tutorial/10-7-stdinitializer_list/


class IntArray
{
private:
    int mLength;
    int *mData;

public:

    IntArray(const std::initializer_list<int>& list)
    {
        std::cout << "Initializer list ctor" << std::endl;

        for (int i = 0; i < list.size(); i++)
        {

        }
    }

    IntArray() : mLength(0), mData(0)
    {
        std::cout << "Simple ctor" << std::endl;
    }

    IntArray(int length) : mLength(length)
    {
        std::cout << "Ctor with one parameter!" << std::endl;
        mData = new int[length];
    }

    ~IntArray()
    {
        delete [] mData;
    }

    int& operator[](int index)
    {
        return mData[index];
    }

    int getLength()
    {
        return mLength;
    }
};


int main()
{
    IntArray array {1,2,3,4,5}; // -std=c++11 required

    std::cout << array.getLength() << std::endl;

    return 0;
}
