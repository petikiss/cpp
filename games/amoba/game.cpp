#include "game.hh"
#include "table_drawer_ascii.hh"

#include <iostream> // TODO: need to be deleted
#include <unistd.h>
#include <cstdlib>
#include <ctime>




Game::Game(int x, int y) : mTable(nullptr), mActivePlayer(X), mGameOver(false), mTableDrawer(nullptr)
{
    srand((unsigned) time(NULL));
    mRobot = new ai::RandomAI();
    mTableDrawer = new tabledrawer::TableDrawerAscii();

    tabledrawer::TableDrawerAscii t;
    newGame(x, y);
}

Game::~Game()
{
    if (mTable != nullptr)
    {
        delete mTable;
    }

    delete mRobot;
}

void Game::newGame(int x, int y)
{
    delete mTable;
    mTable = new table::Table(x,y);
    mTable->print();
    start();
}


void Game::start()
{
    if ((rand() % 2) == 0)
    {
        mActivePlayer = O; // TODO: should be random generated
    }

    while(!mGameOver)
    {
        std::cout << "Game happens...\n";
        for (int i = 0; i < 5; ++i)
        {
            sleep(1);
            if (mActivePlayer == O)
            {
                int pos;
                std::cout << "Human player turn: ";
                std::cin >> pos;
                mActivePlayer = X;
            }
            else
            {
                std::cout << "Computer turn: ";
                mActivePlayer = O;
                table::Position* position = mRobot->calculate(mTable);
                std::cout << "Computer position:" << position->_x << "," << position->_y << std::endl;
                delete position;
            }
        }
        mGameOver = true;
    }
}
