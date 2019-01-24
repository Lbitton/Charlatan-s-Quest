#ifndef BUILDING_H
#define BUILDING_H
#include "Player.h"
#include <string>


class Building
{
    public:
        Building();
        Building(std::string name);
        virtual ~Building();

        void displayBuilding();
        bool upgrade(Player &player);

        int getLvl();
     //   int getCost();
        int getBonusAtk();
        int getBonusDef();
        int getBonusLife();
        int getBonusMana();
        std::string getName();

        void modifLvl(int lvl);
    //    void setCost(int cost);
        void modifBonusAtk(int bonusA);
        void modifBonusDef(int bonusD);
        void modifBonusLife(int bonusL);
        void modifBonusMana(int bonusM);

    protected:

    private:
  //      int _unlock;
        int _level;
        int _bonusAtk;
        int _bonusDef;
        int _bonusPvMax;
        int _bonusManaMax;
        int _bonusStressMax;
        std::string _name;
};

#endif // BUILDING_H
