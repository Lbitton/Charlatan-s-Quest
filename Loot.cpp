#include "Loot.h"

Loot::Loot()
{
    //ctor
}

Loot::~Loot()
{
    //dtor
}

void Loot::collect(Player &player){
    std::string answerUnlock;
    int idLoot = rand()%10 +1;

    initLoot(idLoot);
    std::cout<<std::endl;
    std::cout<<"You have found a "<<_name<<"."<<std::endl;
    if(_locked==true){
        std::cout<<"However, it appears to be locked."<<std::endl;
        if(player.getKeys()>0){
                std::cout<<"Would you like to unlock it ? 1.Yes | 2.No "<<"("<<player.getKeys()<<" keys left)"<<std::endl;
                std::cin>>answerUnlock;
                while(answerUnlock!= "1" && answerUnlock!= "2"){
                    std::cout<<"1. Yes   |   2. No     ?";
                    std::cin>>answerUnlock;
                    std::cout<<std::endl;
                }
                if(answerUnlock=="1"){
                    player.modifKeys(-1);
                    displayLoot(player);
                }
                else{
                    std::cout<<"You've decided to walk away and to keep those precious keys for a better occasion."<<std::endl;
                }
        }
    }
    else{
        displayLoot(player);
    }
}

void Loot::displayLoot(Player &player){

    std::cout<<_display<<std::endl;

    if(_gold>0 || _lPotions>0 || _mPotions>0 || _keys>0){
    std::cout<<"You have obtained ";
    }

    if(_gold>0){
        std::cout<<_gold<<" gold coins | ";
        player.modifGold(_gold);
    }
    if(_lPotions>0){
        std::cout<<_lPotions<<" life potions | ";
        player.modifLifePotion(_lPotions);
    }
    if(_mPotions>0){
        std::cout<<_mPotions<<" mana potions | ";
        player.modifManaPotion(_mPotions);
    }
    if(_keys>0){
        std::cout<<_keys<<" keys | ";
        player.modifKeys(_keys);
    }
    if(_gear>0){
        std::cout<<"GEAR UNDER INTEGRATION"<<std::endl; //A INTEGRER

    }
    std::cout<<std::endl;
    if(_damage>0){
        std::cout<<"You have suffered "<<_damage<<" damage points while checking that "<<_name<<"."<<std::endl;
        player.modifLifeActual(-_damage);
    }
    //STATUS A INTEGRER
}

void Loot::initLoot(int idLoot){
    std::ifstream inFile;
    inFile.open("Loot.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }else{
        std::string line;
        inFile.seekg(std::ios::beg);
        for(int i=0; i < idLoot - 1; ++i){
           // inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           inFile.ignore(1000,'\n');
        }
        std::getline(inFile, line);
        std::vector<std::string> lootInit = StaticFunctions::split(line, ':');
        _name=lootInit[0];
        _display=lootInit[1];
        _gold=std::stoi(lootInit[2]);
        _lPotions=std::stoi(lootInit[3]);
        _mPotions=std::stoi(lootInit[4]);
        _keys=std::stoi(lootInit[5]);
        _gear=std::stoi(lootInit[6]);
        _damage=std::stoi(lootInit[7]);
        _status=std::stoi(lootInit[8]);
        _locked=std::stoi(lootInit[9]);
    }
    inFile.close();
}
