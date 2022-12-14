#ifndef TABLE_DRAWER
#define TABLE_DRAWER

namespace table
{
class Table;
}


namespace tabledrawer
{

class TableDrawer
{
public:
        TableDrawer();
        virtual void draw(table::Table* table) = 0;
};

} // namespace tabledrawer

#endif // TABLE_DRAWER

