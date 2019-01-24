#ifndef ITEMMERCHANT_H
#define ITEMMERCHANT_H
#include "Player.h"
#include <string>
#include <iostream>

class ItemMerchant
{
    public:
        ItemMerchant();
        virtual ~ItemMerchant();

        std::string greet();
        std::string sellItems(Player &player);
        void encounter(Player &player);
        void displayGoods();
        void sellLifePotions(Player &player);
        void sellManaPotions(Player &player);
        void sellAntidotes(Player &player);
        void sellKeys(Player &player);

        int getNbLifePotions();
        int getNbManaPotions();
        int getNbAntidotes();
        int getNbKeys();
        void setLifePotions(int potion);
        void setManaPotions(int potion);
        void setNbAntidotes(int antidote);
        void setKeys(int keys);

    protected:

    private:
        int _nbLifePotions;
        int _nbManaPotions;
        int _nbAntidotes;
        int _keys;
};

#endif // ITEMMERCHANT_H
