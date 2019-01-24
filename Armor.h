#ifndef ARMOR_H
#define ARMOR_H
#include "Equipment.h"

class Armor : public Equipment
{
    public:
        Armor();
        Armor(std::string nameArmorBase, int bAtkArmorBase, int bDefArmorBase);
        virtual ~Armor();
        //surcharge pour avoir le bon fichier txt.
       // std::vector<std::string> readEquipmentFile(int idEquip);

    protected:

    private:
};

#endif // ARMOR_H
