#include <iostream>


class IntArray
{
private:
    int mLength;
    int *mData;

public:
    IntArray() : mLength(0), mData(0)
    {
    }

    IntArray(int length) : mLength(length)
    {
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
    // This code won’t compile, because the IntArray class doesn’t have a
    // constructor that knows what to do with an initializer list.
    // As a result, we’re left initializing our array elements individually:

    /* IntArray array {1,2,3,4,5}; // this line doesnt compile */

    IntArray array(5);

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    for(int i = 0; i < 5; i++)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
