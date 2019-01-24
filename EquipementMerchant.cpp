#include "EquipementMerchant.h"

EquipementMerchant::EquipementMerchant()
{
    _type = rand()%2;
    _idEquip = rand()%10+1;
    if(_type == 0){
        _armor.initEquipment(_idEquip, 0);

    }
    else{
        _weapon.initEquipment(_idEquip, 1);
    }
}


std::string EquipementMerchant::greet(){
    std::string input;

    if(_type==0){
        std::cout<<"\"Greetings fella ! You are right on time, I have found one hell of an armor !\""<<std::endl;
    }
    else if(_type ==1){
        std::cout<<"\"Aaaah, I was looking for you, stranger ! I've just got a brand new weapon in stock, and I was looking for you !\""<<std::endl;
    }
    std::cout<<"\"Would you like to check it out?\" 1.Yes 2.No"<<std::endl;
    std::cin>>input;
    while(input != "1" && input !="2"){
        std::cout<<"\"I'm.... Afraid I don't understand mate, must be stressful to wander around here eh ? So, wanna check it ? 1.Yes 2.No\""<<std::endl;
    }

    return input;
}

void EquipementMerchant::encounter(Player &player){
    std::cout<<"As you push the door, you see a bulky fella, carrying what seems to be an extremely heavy bag. As he sees you, he smiles widely:"<<std::endl;
    std::string decision = greet();
    if(decision == "1"){
        displayGoods();
        if(_type==0){
            sellArmor(player);
        }
        else if(_type == 1){
            sellWeapon(player);
        }
    }
    else{
        std::cout<<"You've decided to keep walking past the merchant. You've already got all that you could possibly need"<<std::endl;
    }
    std::cout<<"As you plunge further in, you hear the merchant bidding you farewell:"<<std::endl;
    std::cout<<"\"See you, stranger, no doubt we will meet again soon, hehehe\""<<std::endl;
}

void EquipementMerchant::displayGoods(){
    if(_type==0){
        std::cout<<"Oh, one can never have too much protection eh ? It's a "<<_armor.getName()<<" which gives a sweet +"<<_armor.getEquiBonusDef()<<" DEF.";
        if(_armor.getEquipBonusAtk()!=0){
            if(_armor.getEquipBonusAtk()>0){
                std::cout<<" And how lucky you are ! It also gives a +"<<_armor.getEquipBonusAtk()<<" ATK."<<std::endl;
            }
            else if(_armor.getEquipBonusAtk()<0){
                std::cout<<" But everything has a price stranger, it will take "<<_armor.getEquipBonusAtk()<<" ATK point from you..."<<std::endl;
            }
            else{
                std::cout<<"And no changes whatsoever to your ATK !"<<std::endl;
            }
        }
        std::cout<<"\"The price ? "<<_armor.getPrice()<<" Gold coins \""<<std::endl;
    }
    else if(_type==1){
        std::cout<<"Aaaah, wanna see the beast eh ? It's a "<<_weapon.getName()<<" with a nice +"<<_weapon.getEquipBonusAtk()<<" ATK.";
        if(_weapon.getEquiBonusDef()!=0){
            if(_weapon.getEquiBonusDef()>0){
                std::cout<<"It also gives a +"<<_weapon.getEquiBonusDef()<<" DEF."<<std::endl;
            }
            else if(_weapon.getEquiBonusDef()<0){
                std::cout<<"The only drawback is that it will diminish your DEF by "<<_weapon.getEquiBonusDef()<<"."<<std::endl;
            }
            else{
                std::cout<<"And it doesn't change your DEF !"<<std::endl;
            }
        }
        std::cout<<"\"And it costs only "<<_weapon.getPrice()<<" gold coins. Hurry up, that's an offer !"<<std::endl;
    }
}

void EquipementMerchant::sellArmor(Player &player){
    std::string decision;
    if(player.getGold()>_armor.getPrice()){
        std::cout<<"\"So, would you like to buy it ? 1.Yes 2.No\""<<std::endl;
        std::cin>>decision;
        while(decision!="1" && decision!="2"){
            std::cout<<"\"What ? I repeat fella: 1.Yes or 2.No\""<<std::endl;
            std::cin>>decision;
        }
        if(decision=="1"){
            std::cout<<"\"Very well, that will cost ya "<<_armor.getPrice()<<" gold coins.\""<<std::endl;
            player.switchArmor(_idEquip);
            player.modifGold(-_armor.getPrice());
            std::cout<<"You have bought the "<<_armor.getName()<<" . You have "<<player.getGold()<<" coins left."<<std::endl;
            std::cout<<"Your new equipments : ";
            player.displayArmorAndWeapon();
            std::cout<<std::endl;
        }
        else{
            std::cout<<"Aaaaah, as you wish, I'll try to find better next time..."<<std::endl;
        }
    }
    else{
        std::cout<<"I'm afraid you don't have enough money for that..."<<std::endl;
    }
}

void EquipementMerchant::sellWeapon(Player &player){
    std::string decision;
    if(player.getGold()>_weapon.getPrice()){
        std::cout<<"\"So, would you like to take the monster ? 1.Yes 2.No\""<<std::endl;
        std::cin>>decision;
        while(decision!="1" && decision!="2"){
            std::cout<<"\"What ? I repeat, mate: 1.Yes or 2.No\""<<std::endl;
            std::cin>>decision;
        }
        if(decision=="1"){
            std::cout<<"\"Very well, that will be "<<_weapon.getPrice()<<" gold coins.\""<<std::endl;
            player.switchWeapon(_idEquip);
            player.modifGold(-_weapon.getPrice());
            std::cout<<"You have bought the "<<_weapon.getName()<<" . You have "<<player.getGold()<<" coins left."<<std::endl;
            std::cout<<"Your new equipments : ";
            player.displayArmorAndWeapon();
            std::cout<<std::endl;
        }
        else{
            std::cout<<"Aaaaah, as you wish, I'll try to find better next time..."<<std::endl;
        }
    }
    else{
        std::cout<<"I'm afraid you don't have enough money for that..."<<std::endl;
    }
}

EquipementMerchant::~EquipementMerchant()
{
    //dtor
}
