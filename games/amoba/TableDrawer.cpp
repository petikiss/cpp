#include "Table.hh"

#include <graphics.h>
#include <conio.h>




void
TableDrawer::draw(Table& table)
{
   for(TableTypeIterator it = table.begin(); it != table.end(); ++it)
   {
      for (std::array<char, 10>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2)
      {
         std::cout << *it2 << " ";
      }
      std::cout << std::endl;
   }
}


void
TableDrawer::draw2()
{

}
