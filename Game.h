#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Entity.h"
#include "Rooms.h"
#include "Player.h"
#include "Monster.h"
#include "Building.h"
#include "Combat.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void introduction(Player& player);
        void maingame(Player &player, Building &forge, Building &academy, Building &hospital, Building &sanctuary);
        void upgradeTown(Player &player, Building &forge, Building &academy, Building &hospital, Building &sanctuary);
        void checkVillageois(Player& player, Building &academy, Building &hospital, Building &sanctuary);

    protected:

    private:
        //int _highScore;
};

#endif // GAME_H
