#ifndef AI_HH
#define AI_HH

namespace table
{
class Table;
class Position;
}


namespace ai
{

class AI
{
public:
    virtual ~AI() {}
    virtual table::Position* calculate(const table::Table* table) = 0;
};


class RandomAI : public AI
{
public:
    RandomAI();
    ~RandomAI();
    virtual table::Position* calculate(const table::Table* table) override;
};


}

#endif
