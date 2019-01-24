#ifndef WEAPON_H
#define WEAPON_H
#include "Equipment.h"


class Weapon: public Equipment
{
    public:
        Weapon();
        Weapon(std::string nameWeaponBase, int bAtkWeaponBase, int bDefWeaponBase);
        virtual ~Weapon();


    protected:

    private:
};

#endif // WEAPON_H
