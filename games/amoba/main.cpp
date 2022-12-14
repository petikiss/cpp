#include <iostream>
#include "game.hh"


int main()
{
    int x, y;
    std::cout << "Amoba game" << std::endl;

    std::cout << "Enter the table size:";
    std::cin >> x;
    std::cin >> y;
    Game game(x, y);

    return 0;
}
