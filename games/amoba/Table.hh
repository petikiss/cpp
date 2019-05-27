
#ifndef TABLE_HH
#define TABLE_HH


#include <array>

typedef std::array<std::array<char, 10>, 10> TableType;
typedef std::array<std::array<char, 10>, 10>::iterator TableTypeIterator;

class Table
{
  public:
   Table();
   void putX(int x, int y);
   void putO(int x, int y);
   bool winnerSituation();

   TableTypeIterator begin() { return mTable.begin(); }
   TableTypeIterator end() { return mTable.end();}
  private:
   int mTableSize;

   TableType mTable;
};





#endif
