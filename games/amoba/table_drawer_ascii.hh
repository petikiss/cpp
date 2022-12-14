#ifndef TABLE_DRAWER_ASCII_HH
#define TABLE_DRAWER_ASCII_HH

#include "table_drawer.hh"

namespace table
{
class Table;
}

namespace tabledrawer
{

class TableDrawerAscii : public TableDrawer
{
public:
        TableDrawerAscii();
        ~TableDrawerAscii();
        void draw(table::Table* table) override;
};

} // namespace tabledrawer

#endif // TABLE_DRAWER_ASCII_HH

