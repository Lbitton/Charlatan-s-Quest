#include "Armor.h"


Armor::Armor(){
    _type = 0;
}

Armor::Armor(std::string nameArmorBase, int bAtkArmorBase, int bDefArmorBase)
{
    //ctor
    _equipmentName = nameArmorBase;
    _bonusAtk = bAtkArmorBase;
    _bonusDef = bDefArmorBase;
    _type = 0;
}

Armor::~Armor()
{
    //dtor
}
