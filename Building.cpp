#include "Building.h"

Building::Building(std::string name)
{
    _name = name;
  //  _unlock = 1;
    if(_name=="Forge"){
        _level = 1;
    }
    else{
        _level = 0;
    }
    _bonusAtk = 0;
    _bonusDef = 0;
    _bonusPvMax = 0;
    _bonusManaMax = 0;

}

Building::~Building()
{
    //dtor
}

bool Building::upgrade(Player &player){
    std::string decision;

    std::cout<<std::flush;
    std::cout<<"You need "<<getLvl()<<" to upgrade the "<<getName()<<". You currently have "<<player.getBlueprints()<<" Blueprints."<<std::endl;
    if(player.getBlueprints()>=getLvl()){
        std::cout<<std::endl;
        std::cout<<"1.Upgrade ? 2.Nevermind"<<std::endl;
        std::cin>>decision;
        std::cout<<std::endl;
        while(decision != "1" && decision !="2"){
            std::cout<<"Hum. I repeat: 1.Upgrade ? 2.Nevermind . Should be easy..."<<std::endl;
            std::cin>>decision;
        }
        if(decision=="1"){
                player.modifBluePrints(-getLvl());
                std::cout<<"The upgrade was a success. You have "<<player.getBlueprints()<<" left."<<std::endl;
                if(getName()=="Forge"){
                    modifBonusAtk(+1);
                    std::cout<<"The forge now gives you +"<<getBonusAtk()<<" in Attack."<<std::endl;
                    player.modifAtk(1);
                    std::cout<<"You have "<<player.getAtk()<<" Atk points. ("<<player.getAtk()-getBonusAtk()<<" + "<<getBonusAtk()<<")"<<std::endl;
                }
                else if(getName()=="Academy"){
                    modifBonusDef(+1);
                    std::cout<<"The academy awards you with a better training, you now have +"<<getBonusDef()<<" Defense."<<std::endl;
                    player.modifDef(1);
                    std::cout<<"You have "<<player.getDef()<<" Def points. ("<<player.getDef()-getBonusDef()<<" + "<<getBonusDef()<<")"<<std::endl;
                }
                else if(getName()=="Hospital"){
                    modifBonusLife(+5);
                    std::cout<<"Thanks to you, more ill and wounded people can rest. You also now have +"<<getBonusLife()<<" Life Points."<<std::endl;
                    player.modifLifeMax(5);
                    std::cout<<"You have "<<player.getLifeMax()<<" Max HP. ("<<player.getLifeMax()-getBonusLife()<<" + "<<getBonusLife()<<")"<<std::endl;
                }
                else if(getName()=="Sanctuary"){
                    modifBonusMana(+5);
                    std::cout<<"Pray the Forgotten Ones, and honor them, for they grant you +"<<getBonusMana()<<" Mana Points."<<std::endl;
                    player.modifManaMax(5);
                    std::cout<<"You have "<<player.getManaMax()<<"Max MP. ("<<player.getManaMax()-getBonusMana()<<" + "<<getBonusMana()<<")"<<std::endl;
                }
                modifLvl(1);
        }
            else if(decision=="2"){
                return false;
        }
        std::cout<<"You will need "<<getLvl()<<" Blueprint to upgrade this building next time"<<std::endl;
        std::cout<<std::endl;
        return true;
    }
    else {
        std::cout<<"Unfortunately, you cannot afford to expand this building. You decide going back into the wolf's den is the best option for now"<<std::endl;
    }
    return false;
}

void Building::displayBuilding(){
    if(_level > 0){
        std::cout<<getName()<<" level "<<getLvl()<<", cost to next level : "<<getLvl()<<" Blueprints."<<std::endl;
        if(getName()=="Forge"){
            std::cout<<"Current Attack bonus : +"<<getBonusAtk()<<"."<<std::endl;
        }
        else if(getName()=="Academy"){
            std::cout<<"Current Defense bonus : +"<<getBonusDef()<<"."<<std::endl;
        }
        else if(getName()=="Hospital"){
            std::cout<<"Current Life bonus : +"<<getBonusLife()<<"."<<std::endl;
        }
        else if(getName()=="Sanctuary"){
            std::cout<<"Current Mana bonus : +"<<getBonusMana()<<"."<<std::endl;
        }
    }else{
        std::cout << getName() << " is closed. The citizen is still trapped within the Dungeon." << std::endl;
    }
}

std::string Building::getName(){
    return _name;
}

int Building::getLvl(){
    return _level;
}

int Building::getBonusAtk(){
    return _bonusAtk;
}
int Building::getBonusDef(){
    return _bonusDef;
}
int Building::getBonusLife(){
    return _bonusPvMax;
}
int Building::getBonusMana(){
    return _bonusManaMax;
}

void Building::modifLvl(int lvl){
    _level += lvl;
}
void Building::modifBonusAtk(int bonusA){
    _bonusAtk += bonusA;
}
void Building::modifBonusDef(int bonusD){
    _bonusDef += bonusD;
}
void Building::modifBonusLife(int bonusL){
    _bonusPvMax += bonusL;
}
void Building::modifBonusMana(int bonusM){
    _bonusManaMax += bonusM;
}

