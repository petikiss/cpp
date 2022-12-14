#include "table.hh"

#include <iostream>

namespace table
{

const int TABLE_EMPTY_POSITION = -1;

Table::Table(int x, int y) : mTable(nullptr)
{
    reset(x, y);
}

Table::~Table()
{

}

void Table::print() const
{
    std::cout << "Tabla:\n";
    for(int i = 0; i < mX; ++i)
    {
        for(int j = 0; j < mY; ++j)
        {
            std::cout << mTable[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void Table::reset(int x, int y)
{
    mX = x;
    mY = y;

    if (mTable != nullptr)
    {
        for(int i = 0; i < mX; ++i)
        {
           delete [] mTable[i];
        }
        delete [] mTable;
    }

    mTable = new int*[x];
    for(int i = 0; i < x; ++i)
    {
        mTable[i] = new int[y];
    }

    for(int i = 0; i < mX; ++i)
    {
        for(int j = 0; j < mY; ++j)
        {
            mTable[i][j]=TABLE_EMPTY_POSITION;
        }
    }
}

void Table::getSize(int& x, int& y) const
{
    x = mX;
    y = mY;
}

bool Table::isFreePosition(int x, int y) const
{
    if ( mTable[x][y] == TABLE_EMPTY_POSITION) return true;

    return false;
}


} // namespace Table
