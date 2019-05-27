
#include "Table.hh"


Table::Table()
{
   for(TableTypeIterator it = mTable.begin(); it != mTable.end(); ++it)
   {
      for (std::array<char, 10>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
      {
         *it2 = '_';
      }
   }
}

void
Table::putX(int x, int y)
{
   mTable[x][y] = 'X';
}


void
Table::putO(int x, int y)
{
   mTable[x][y] = 'O';
}


bool
Table::winnerSituation()
{
   const int winCount = 5;

   for(int i = 0; i < 10; ++i)
   {
      for (int j = 0; j < 10; ++j)
      {
         if ( mTable[i][j] != '_')
         {
            // horizontal check
            // left
            int left = 0;
            for (int k = j-1; k > 0 && mTable[i][k] == mTable[i][j]; ++k)
            {
               left++;
            }

            int right = 0;
            for(int k = j+1; k < 10 && mTable[i][k] == mTable[i][j]; ++k)
            {
               right++;
            }

            if (left+right+1 >= winCount)
            {
               return true;
            }
         }
      }
   }

   return false;
}
