#include "AI.hh"

#include "table.hh"

#include <iostream> // TODO: delete this

#include <unistd.h>
#include <cstdlib>
#include <ctime>

namespace ai
{

RandomAI::RandomAI()
{
    srand((unsigned) time(NULL));
}

RandomAI::~RandomAI()
{
}

table::Position* RandomAI::calculate(const table::Table* table)
{
    int x, y;

    std::cout << "Calculate is called!" << std::endl;
    table->getSize(x, y);
    bool newPositionFound = false;
    int randomX = -1;
    int randomY = -1;
    while(!newPositionFound)
    {
        randomX = rand() % x;
        randomY = rand() % y;

        if (table->isFreePosition(randomX, randomY))
        {
            newPositionFound = true;
        }
    }

    return new table::Position(randomX, randomY);
}

} // namespace ai
