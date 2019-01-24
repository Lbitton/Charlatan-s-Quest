#ifndef OFFENSIFTECHNIQUE_H
#define OFFENSIFTECHNIQUE_H
#include <string>

#include "Entity.h"

class OffensifTechnique
{
    public:

        OffensifTechnique(std::string techName, int manaCost, float attDmg, int attNbr, int statusInflicted, int statusCtr, std::string type);
        virtual ~OffensifTechnique();
        void UseOffTechnique(Entity &player, Entity &cible);
        void modifTech(std::string newName, int newManaCost, float newAttDmg, int newAttNbr, int newStatusInflicted, int newStatusCtr, std::string type);
        std::string getAtkName();
        float getAtkStrenght();
        int getAtkNbr();
        int getManaCost();

    protected:

    private:
        std::string _atkName;
        int _manaCost;
        float _atkStrenght; // % de dmg.
        int _atkNbr;
        int _statusInflicted;
        int _counterStatusInflicted;
        std::string _type;
};

#endif // OFFENSIFTECHNIQUE_H
