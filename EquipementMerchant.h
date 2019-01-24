#ifndef EQUIPEMENTMERCHANT_H
#define EQUIPEMENTMERCHANT_H
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"

#include <string>
#include <iostream>


class EquipementMerchant
{
    public:
        EquipementMerchant();
        virtual ~EquipementMerchant();

        std::string greet();
        void encounter(Player &player);
        void displayGoods();
        void sellWeapon(Player &player);
        void sellArmor(Player &player);



    protected:

    private:
        Armor _armor;
        Weapon _weapon;
        int _gold;
        int _type;
        int _idEquip;
};

#endif // EQUIPEMENTMERCHANT_H
