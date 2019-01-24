#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <fstream>
//#include <sstream>
//#include <vector>
//#include <limits>

#include "Entity.h"
#include "StaticFunctions.h"
#include "StaticMonsterTechniques.h"

class Monster: public Entity
{
    public:
        Monster();
        virtual ~Monster();
       // void displayMonster();
        void monsterATKmenu(Player &target);
        void initMonster(int idMonster);

        void changeInitiative(int newInitiative);
        int getInitiative();
        std::string getMonsterType();

    protected:
        std::string _monsterType;
        int _initiative;
    private:

};

#endif // MONSTER_H
