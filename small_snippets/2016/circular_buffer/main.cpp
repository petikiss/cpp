#include <iostream>
#include <cmath>

int begin = 0;
int end = 0;
int write = 0;

char array[5] = {'0','0','0','0','0'};
int SIZE = 5;

int next(int i)
{
    int result = (i+1)%SIZE;
//    std::cout << "i: " << i << " result: " << result << std::endl;
    return result;
}

void insert(char ch)
{
    array[write] = ch;

    begin = write%5;
    end = (write !=0) ? write-1 : SIZE-1;
    write = (write + 1) % 5;

    std::cout << "write: " << write << " begin: " << begin << " end: " << end << std::endl;
}


void print()
{
    std::cout << "PRINT: ";
    for(int i = begin; i != end; i=next(i))
    {
        if (array[i] != '0')
        {
            std::cout << array[i] << " ";
        }
    }
}


int main()
{
    char ch;
    std::cin >> ch;

    while (ch != 'c')
    {
        insert(ch);
        print();
        std::cout << std::endl;
        std::cin >> ch;
    }
}



