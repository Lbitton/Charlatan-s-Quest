#ifndef BOSS_H
#define BOSS_H
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Player.h"
#include "StaticFunctions.h"
#include "StaticBossTechniques.h"


class Boss: public Monster
{
    public:
        Boss();
        virtual ~Boss();

        void bossATKMenu(Player &target);
        void initBoss(int idBoss);
        void heal();

    protected:

    private:
};

#endif // BOSS_H
