#include <iostream>

int main()
{
    int i = 0;
    for( ;;)
    {
        if (i%2 == 0)
        {
            break;
        }
        else
        {
            std::cout << i << std::endl;
        }
    }
    std::cout << "end\n";
    return 0;
}
