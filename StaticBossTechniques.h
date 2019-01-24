#ifndef STATICBOSSTECHNIQUES_H
#define STATICBOSSTECHNIQUES_H

#include "Boss.h"
#include "Player.h"
#include "Monster.h"
//#include "Combat.h"  Je voulais le faire pour des invocations, mais ça provoque une inclusion multiple ici. Je checkerai plus pour faire ça dans bossFight()

class StaticBossTechniques
{
    public:
        StaticBossTechniques();
        virtual ~StaticBossTechniques();

        static void giantSmash(Entity &currentBoss, Player &player);
        static void giantBoulderThrow(Entity &currentBoss, Player &player);

        static void mindControl(Entity &currentBoss, Player &player);
        static void mindSummon(Entity &currentBoss, Player &player);

        static void abyssStrike(Entity &currentBoss, Player &player);
        static void abyssDespair(Entity &currentBoss, Player &player);

        static void dominionLight(Entity &currentBoss, Player &player);
        static void dominionPureStrike(Entity &currentBoss, Player &player);

        static void calamityDecimate(Entity &currentBoss, Player &player);
        static void calamityFeed(Entity &currentBoss, Player &player);

    protected:

    private:
};

#endif // STATICBOSSTECHNIQUES_H
