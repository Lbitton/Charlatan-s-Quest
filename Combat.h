#ifndef COMBAT_H
#define COMBAT_H
#include "Entity.h"
#include "Monster.h"
#include "Player.h"
#include "Boss.h"
#include "StaticEvents.h"

class Combat
{
    public:
        Combat();
        virtual ~Combat();
       // void fightControl(Player &player, Monster &monster);
        void bossFight(Player &player, Boss &boss);
        void fightControl(Player &player, Monster &monster);
        void fightControl2Enemy(Player &player, Monster &monster, Monster &monster2);
        void fightControl3Enemy(Player &player, Monster &monster, Monster &monster2, Monster &monster3);
        void displayHP(Entity &entity);

    protected:

    private:
};

#endif // COMBAT_H
