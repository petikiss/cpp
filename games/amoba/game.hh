#ifndef GAME_HH
#define GAME_HH

#include "table.hh"
#include "AI.hh"

namespace tabledrawer
{
class TableDrawer;
}


class Game
{
public:
    Game(int x, int y);
    ~Game();
    void newGame(int x, int y);
private:
    void start();
    table::Table* mTable;

    enum Player {X, O};
    Player mActivePlayer;
    bool mGameOver;
    ai::AI* mRobot;
    tabledrawer::TableDrawer* mTableDrawer;
};


#endif // GAME_HH
