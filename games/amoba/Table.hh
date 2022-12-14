#ifndef TABLE_HH
#define TABLE_HH

namespace table
{

struct Position
{
    Position(int x, int y) : _x(x), _y(y) {}
    int _x;
    int _y;
};


class Table
{
public:
    Table(int x, int y);
    ~Table();
    void reset(int x, int y);
    void print() const; // debug purpose
    void getSize(int& x, int& y) const;
    bool isFreePosition(int x, int y) const;
private:
    int **mTable;
    int mX;
    int mY;
};


} // namespace Table

#endif // TABLE_HH
