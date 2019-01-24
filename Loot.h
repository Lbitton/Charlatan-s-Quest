#ifndef LOOT_H
#define LOOT_H
#include "Player.h"
#include "StaticFunctions.h"

#include <string>
#include <iostream>
#include <fstream>
//#include <limits>
//#include <vector>



class Loot
{
    public:
        Loot();
        virtual ~Loot();

        void initLoot(int idLoot);
        void displayLoot(Player &player);
        void collect(Player &player);

    protected:

    private:
        int _gold;
        int _lPotions;
        int _mPotions;
        int _keys;
        int _gear;
        int _damage;
        int _status;
        int _locked;
        std::string _name;
        std::string _display;
};

#endif // LOOT_H
