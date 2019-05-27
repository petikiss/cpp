#include "Table.hh"
#include "TableDrawer.hh"

#include <iostream>

int main()
{
   Table table;

   TableDrawer drawer;


//   table.putX(1,9);

   drawer.draw(table);


   int maxRound = 15;

   while (maxRound > 0 && !table.winnerSituation())
   {
      int x, y;

      std::cout << "X player:\n";
      std::cout << "x:";
      std::cin >> x;
      std::cout << "y:";
      std::cin >> y;
      table.putX(x,y);

      std::cout << std::endl;
      drawer.draw(table);


      std::cout << "O player:\n";
      std::cout << "x:";
      std::cin >> x;
      std::cout << "y:";
      std::cin >> y;

      table.putO(x,y);

      std::cout << std::endl;
      drawer.draw(table);

      std::cout << std::endl;
      --maxRound;
   }

   if (table.winnerSituation())
   {
      std::cout << "Somebody won the game!\n";
   }

   std::cout << "Game Ower\n";
}
