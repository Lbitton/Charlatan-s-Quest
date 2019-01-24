#ifndef STATICMONSTERTECHNIQUES_H
#define STATICMONSTERTECHNIQUES_H

#include "Entity.h"
#include "Player.h"


class StaticMonsterTechniques
{
    public:
        StaticMonsterTechniques();
        virtual ~StaticMonsterTechniques();

        static void humanoidBaseAtk(Entity &activeMonster, Player &cible);
        static void humanoidSlashAtk(Entity &activeMonster, Player &cible);
        static void humanoidBattleSongSpell(Entity &activeMonster, Player &cible);

        static void beastPoisonBit(Entity &activeMonster, Player &cible);
        static void beastCrawl(Entity &activeMonster, Player &cible);
        static void beastIntimidate(Entity &activeMonster, Player &cible);

        static void apparitionHaunt(Entity &activeMonster, Player &cible);
        static void apparitionBoilFlesh(Entity &activeMonster, Player &cible);
        static void apparitionWeakCurse(Entity &activeMonster, Player &cible);

    protected:

    private:
};

#endif // STATICMONSTERTECHNIQUES_H
