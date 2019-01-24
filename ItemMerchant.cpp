#include "ItemMerchant.h"

ItemMerchant::ItemMerchant()
{
    _nbLifePotions=rand()%3;                        //Initialisation avec intentaire variable
    _nbManaPotions=rand()%3;
    _nbAntidotes = rand()%2;
    _keys=rand()%2;
}

ItemMerchant::~ItemMerchant()
{
    //dtor
}

void ItemMerchant::encounter(Player &player){
    std::string decision;
    std::cout<<std::endl;

    std::cout<<"You've encountered a nice looking man, standing next to a big and loaded backpack."<<std::endl;
    if(_nbLifePotions>0 || _nbManaPotions>0 || _keys>0 || _nbAntidotes>0){
        decision = greet();
        if(decision == "1"){
            decision = sellItems(player);
            while(decision!="5"){
                if(_nbLifePotions>0 || _nbManaPotions>0 || _keys>0 || _nbAntidotes>0){
                    displayGoods();
                    decision = sellItems(player);
                }
                else{
                    std::cout<<"\"I'm sorry sir, I'm afraid I've ran out of supplies. Why don't you continue your journey while I restock back at town ?"<<std::endl;
                    std::cout<<"After bidding good fortune to the merchant, you've decided to keep the exploration where you've left it."<<std::endl;
                    decision = "5";
                    std::cout<<std::endl;
                }
            }
        }
        else{
            std::cout<<"\"Alright, may you travel safely stranger. \""<<std::endl;
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"\"Uhm, you're surprising me stranger, I still haven't finished to get new items..\""<<std::endl;
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

std::string ItemMerchant::greet(){
    std::string input;
    std::cout<<"\"Come in friend, would you like to buy some of my wares ?\""<<std::endl;
    displayGoods();
    std::cout<<"Deal with the man ? 1.Yes | 2.No"<<std::endl;
    std::cin>>input;
    while(input != "1" && input!= "2"){
        std::cout<<"\"What ? I did not understand..\" Buy something ? 1. Yes | 2. No"<<std::endl;
        std::cin>>input;
    }
    return input;
}

void ItemMerchant::displayGoods(){
    std::cout<<"\"I have "<<getNbLifePotions()<<" Life Potions, "<<getNbManaPotions()<<" Mana Potions, "<<getNbAntidotes()<<" antidotes and "<<getNbKeys()<<" keys left.\""<<std::endl;
}

std::string ItemMerchant::sellItems(Player &player){
    std::string input;
    std::cout<<std::flush;
    std::cout<<"What would you like to buy ?"<<std::endl;
    std::cout<<"1. Life Potions (30 coins) | 2. Mana Potions (30 coins) | 3. Keys (70 coins) | 4. Antidote (50 coins) | 5.Nevermind"<<std::endl;
    do{
        std::cout<<"Your choice : ";
        std::cin>>input;
    }while(input != "1" && input != "2" && input !="3" && input !="4" && input != "5");
    if(input=="1"){
        sellLifePotions(player);
    }
    else if(input=="2"){
        sellManaPotions(player);
    }
    else if(input=="3"){
        sellKeys(player);
    }
    else if(input=="4"){
        sellAntidotes(player);
    }
    else if(input=="5"){
        std::cout<<"You've decided to walk away"<<std::endl;
    }
    else{
        std::cout<<"You've walked away."<<std::endl;
    }
    return input;
}


void ItemMerchant::sellLifePotions(Player &player){
    int nb;
    if(player.getGold()>30){
        if(player.getLifePotions()<10){
            if(getNbLifePotions()>0){
                std::cout<<"\"30 coins for each potion friend. How much would you like to buy ? \""<<std::endl;
                std::cin>>nb;
                while(nb>getNbLifePotions()){
                    std::cout<<"\"I do not have that many life potions, I'm afraid... Try again :\""<<std::endl;
                    std::cin>>nb;
                }
                while(player.getGold()<nb*30){
                    std::cout<<"\"It seems you do not have enough money... You can only afford "<<player.getGold()/30<<" potions..\""<<std::endl;
                    std::cout<<"\"How much would you like to buy ?\""<<std::endl;
                    std::cin>>nb;
                }
                player.modifGold(-nb*30);
                player.modifLifePotion(nb);
                setLifePotions(getNbLifePotions()-nb);
                std::cout<<"You have bought "<<nb<<" Life potions."<<std::endl;
            }
            else {
                std::cout<<"\"I'm afraid I'm out of those...\""<<std::endl;
            }
        }
        else{
            std::cout<<"\"You already have your pockets full of potions friend !\""<<std::endl;
        }
    }
    else{
        std::cout<<"You do not have enough money for that..."<<std::endl;
    }
}

void ItemMerchant::sellManaPotions(Player &player){
    int nb;
    if(player.getGold()>30){
        if(player.getManaPotions()<10){
            if(getNbManaPotions()>0){
                std::cout<<"\"That'll be 30 coins each. How much would you like to buy ? \""<<std::endl;
                std::cin>>nb;
                while(nb>getNbManaPotions()){
                    std::cout<<"\"I do not have that many mana potions, I'm afraid... Try again :\""<<std::endl;
                    std::cin>>nb;
                }
                while(player.getGold()<nb*30){
                    std::cout<<"\"It seems you do not have enough money... You can only afford "<<player.getGold()/30<<" potions..\""<<std::endl;
                    std::cout<<"\"How much would you like to buy ?\""<<std::endl;
                    std::cin>>nb;
                }
                player.modifGold(-nb*30);
                player.modifManaPotion(nb);
                setManaPotions(getNbManaPotions()-nb);
                std::cout<<"You have bought "<<nb<<" Mana potions."<<std::endl;
            }
            else {
                std::cout<<"\"I'm afraid I'm out of those...\""<<std::endl;
            }
        }
        else{
            std::cout<<"\"You already have your pockets full of mana potions friend !\""<<std::endl;
        }
    }
    else{
        std::cout<<"You do not have enough money for that..."<<std::endl;
    }
}

void ItemMerchant::sellAntidotes(Player &player){
    int nb;
    if(player.getGold()>50){
        if(player.getAntidotes()<5){
            if(getNbAntidotes()>0){
                std::cout<<"\"That'll be 50 coins each. How much would you like to buy ? \""<<std::endl;
                std::cin>>nb;
                while(nb>getNbAntidotes()){
                    std::cout<<"\"Oh lord, my stock is not limitless, I'm afraid... Try again :\""<<std::endl;
                    std::cin>>nb;
                }
                while(player.getGold()<nb*50){
                    std::cout<<"\"It seems you do not have enough money... You can only afford "<<player.getGold()/50<<" antidotes..\""<<std::endl;
                    std::cout<<"\"How much would you like to buy ?\""<<std::endl;
                    std::cin>>nb;
                }
                player.modifGold(-nb*50);
                player.modifAntidote(nb);
                setNbAntidotes(getNbAntidotes()-nb);
                std::cout<<"You have bought "<<nb<<" Antidotes."<<std::endl;
            }
            else {
                std::cout<<"\"I'm afraid I'm out of those...\""<<std::endl;
            }
        }
        else{
            std::cout<<"\"You can't carry any more antidote sir !\""<<std::endl;
        }
    }
    else{
        std::cout<<"You do not have enough money for that..."<<std::endl;
    }
}
void ItemMerchant::sellKeys(Player &player){
    int nb;
    if(player.getGold()>70){
        if(player.getKeys()<6){
            if(getNbKeys()>0){
                std::cout<<"\"Those cost 70 coins each. How much would you like to buy ? \""<<std::endl;
                std::cin>>nb;
                while(nb>getNbKeys()){
                    std::cout<<"\"I do not have that many keys, Those do not grow on trees y'know. Try again :\""<<std::endl;
                    std::cin>>nb;
                }
                while(player.getGold()<nb*70){
                    std::cout<<"\"It seems you do not have enough money... You can only afford "<<player.getGold()/70<<" keys with what you have..\""<<std::endl;
                    std::cout<<"\"How much would you like to buy ?\""<<std::endl;
                    std::cin>>nb;
                }
                player.modifGold(-nb*70);
                player.modifKeys(nb);
                setKeys(getNbKeys()-nb);
                std::cout<<"You have bought "<<nb<<" keys."<<std::endl;
            }
            else {
                std::cout<<"\"I'm afraid I'm out of those...\""<<std::endl;
            }
        }
        else{
            std::cout<<"\"You already have your pockets full of potions friend !\""<<std::endl;
        }
    }
    else{
        std::cout<<"You do not have enough money for that..."<<std::endl;
    }
}

int ItemMerchant::getNbLifePotions(){
    return _nbLifePotions;
}
int ItemMerchant::getNbManaPotions(){
    return _nbManaPotions;
}
int ItemMerchant::getNbAntidotes(){
    return _nbAntidotes;
}
int ItemMerchant::getNbKeys(){
    return _keys;
}
void ItemMerchant::setLifePotions(int potion){
    _nbLifePotions = potion;
}
void ItemMerchant::setManaPotions(int potion){
    _nbManaPotions = potion;
}
void ItemMerchant::setNbAntidotes(int antidote){
    _nbAntidotes = antidote;
}
void ItemMerchant::setKeys(int keys){
    _keys = keys;
}
