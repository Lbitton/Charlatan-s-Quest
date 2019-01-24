#include "OffensifTechnique.h"

/*
        void UseOffTechnique(Entity &player, Entity &cible);
        std::string getAtkName();
        float getAtkStrenght();
        int getAtkNbr();
        int getManaCost();
        void modifTech(std::string newName, int newManaCost, float newAttDeg, int newAttNbr, int newStatusInflicted, int newStatusCtr);
*/

OffensifTechnique::OffensifTechnique(std::string techName, int manaCost, float attDmg, int attNbr, int statusInflicted, int statusCtr, std::string type){
    //ctor
    _atkName = techName;
    _manaCost = manaCost;
    _atkStrenght = attDmg;
    _atkNbr = attNbr;
    _statusInflicted = statusInflicted;
    _counterStatusInflicted = statusCtr;
    _type = type;
}

OffensifTechnique::~OffensifTechnique()
{
    //dtor
}

void OffensifTechnique::UseOffTechnique(Entity &activeEntity, Entity &target){
    if(_atkName == "Gigue"){
        float randStrgAtk = rand()%3+ 0.5;
        int randNbAtk = rand()%3+1;
        activeEntity.dealDamage(target, activeEntity.getAtk()*randStrgAtk, randNbAtk, _type);
        //std::cout << "test. " << randStrgAtk << "modif strg and " << randNbAtk << " nb Attk." << std::endl;
    }else{
        activeEntity.dealDamage(target, activeEntity.getAtk()*_atkStrenght, _atkNbr, _type);
    }

    // avec la map
    target.modifStatus(_statusInflicted, _counterStatusInflicted);


    if(_atkName == "Eureka !"){
            //test, voir si ça marche, cible meurt
            target.modifLifeActual(0);
            std::cout << target.getName() << " dies. Just like that." << std::endl;
        }else if(_atkName == "Empale"){
            // se blesse en attaquant
            activeEntity.modifLifeActual(-2);
            std::cout << "The Fakir wounds itself with Empale for 2." << std::endl;
        }else if(_atkName == "Rain of whip"){
            activeEntity.modifStatus(2,2);
            std::cout << "The Fakir bleeds." << std::endl;
            // se fait saigner aussi
        }else if(_atkName == "Revel"){
            // gagne bonus d'atk en fct de vie perdu
            std::cout << "Pain is life. Pain is strength. The Fakir gains an amount of bonusAtk equal to "
                << (activeEntity.getLifeMax()-activeEntity.getLifeActual())/5 << std::endl;
            activeEntity.modifBonusAtk((activeEntity.getLifeMax()-activeEntity.getLifeActual())/5);
        }else if(_atkName == "Shadow Daggers"){
            while(activeEntity.getManaActual()>0){
                std::cout << activeEntity.getName() << " throws a dagger made of shadow. " << target.getName()
                    << " takes " << activeEntity.getAtk() << " damages (not reduced by " << target.getName() << "'s def)." << std::endl;
                if(target.getLifeActual() >= activeEntity.getAtk()){
                    target.modifLifeActual(-activeEntity.getAtk());
                }else{
                    target.modifLifeActual(0);
                    target.modifResilience(-activeEntity.getAtk());
                }
                activeEntity.modifManaActual(-2);
            }
            if(activeEntity.getManaActual() < 0){
                activeEntity.modifManaActual(0);
            }
        }else if(_atkName == "A votre bon vouloir"){
            activeEntity.modifBonusAtk(-1);
            std::cout << "The dance restore all mana to the Jester but the exhaustion takes its tall. -1 Atk." << std::endl;
        }else if(_atkName == "Ice barriere"){
            std::cout << "The ice protects you. +2 def" << std::endl;
            activeEntity.modifBonusDef(2);
        }
}

void OffensifTechnique::modifTech(std::string newName, int newManaCost, float newAttDmg, int newAttNbr,int newStatusInflicted, int newStatusCtr, std::string type){
    _atkName = newName;
    _manaCost = newManaCost;
    _atkStrenght = newAttDmg;
    _atkNbr = newAttNbr;
    _statusInflicted = newStatusInflicted;
    _counterStatusInflicted = newStatusCtr;
    _type = type;
}


std::string OffensifTechnique::getAtkName(){
    return _atkName;
}

float OffensifTechnique::getAtkStrenght(){
    return _atkStrenght;
}

int OffensifTechnique::getAtkNbr(){
    return _atkNbr;
}

int OffensifTechnique::getManaCost(){
    return _manaCost;
}


