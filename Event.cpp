#include "Event.h"

Event::Event()
{
    //ctor
}

Event::~Event()
{
    //dtor
}

void Event::execute(Player &player){
    int idEvent = rand()%20 +1;
    //le joueur a 66% de chance de décider s'il veut ou pas explorer. Autrement l'event se produit directement.
    int choice = rand()%3;
    std::string answerExplore;

    initEvent(idEvent);
    std::cout<<std::endl;
    if(choice==0){
        std::cout<<"As you exit the room, you find yourself in a "<<_name<<"."<<std::endl;
        describe(player);
    }
    else{
        std::cout<<"You find yourself in a "<<_name<<"."<<std::endl;
        std::cout<<_display<<std::endl;
        std::cout<<"1.Yes | 2.No "<<std::endl;
        std::cin>>answerExplore;
        while(answerExplore != "1" && answerExplore != "2"){
            std::cout<<"Invalid answer. Please try again."<<std::endl;
            std::cin>>answerExplore;
        }
        if(answerExplore=="1"){
            describe(player);
        }
        else{
            std::cout<<"You have decided to hurry your way through the "<<_name<<"."<<std::endl;
        }
    }
    std::cout<<std::endl;
}

void Event::describe(Player &player){
    //std::cout<<_event<<std::endl;
    if(_damage>0){
        std::cout<<"It's a trap ! You take "<<_damage<<" damage."<<std::endl;
        player.modifLifeActual(-_damage);
        std::cout<<"You have "<<player.getLifeActual()<<" HP left."<<std::endl;
    }

    if(_presence>0){
            std::cout << "Ready yourself, the corridor is not empty !" << std::endl;
        int id1 = rand()%4+1;
        int id2 = rand()%4+1;
        int id3 = rand()%4+1;
        Combat fight;

        if(_presence==1){
            Monster monster;
            monster.initMonster(id1);
            if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                monster.changeInitiative(1);
            }
            if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                monster.changeInitiative(0);
            }

            std::cout<<monster.getName()<<" attacks !"<<std::endl;
            fight.fightControl(player, monster);
        }
        else if(_presence==2){
            Monster monster;
            Monster monster2;
            monster.initMonster(id1);
            monster2.initMonster(id2);
            if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                monster.changeInitiative(1);
                monster2.changeInitiative(1);
            }
            if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                monster.changeInitiative(0);
                monster2.changeInitiative(0);
            }

            std::cout<<monster.getName()<<" and "<<monster2.getName()<<" attack !"<<std::endl;
            fight.fightControl2Enemy(player, monster, monster2);
        }
        else if(_presence==3){
            Monster monster;
            Monster monster2;
            Monster monster3;
            monster.initMonster(id1);
            monster2.initMonster(id2);
            monster3.initMonster(id3);
            if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                monster.changeInitiative(1);
                monster2.changeInitiative(1);
                monster3.changeInitiative(1);
            }
            if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                monster.changeInitiative(0);
                monster2.changeInitiative(0);
                monster3.changeInitiative(0);
            }

            std::cout<<monster.getName()<<", "<<monster2.getName()<<" and "<<monster3.getName()<<" charge !"<<std::endl;
            fight.fightControl3Enemy(player, monster, monster2, monster3);
        }
    }

    if(_gold>0){
        std::cout<<"You have found "<<_gold<<" gold coins."<<std::endl;
        player.modifGold(_gold);
        std::cout<<"You have "<<player.getGold()<<" coins."<<std::endl;
    }

    if(_loot>0){
        Loot loot;
        int idLoot= rand()%10+1;
        loot.initLoot(idLoot);
        loot.collect(player);
    }
}


void Event::initEvent(int idEvent){
    std::ifstream inFile;
    inFile.open("Event.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }else{
        std::string line;
        inFile.seekg(std::ios::beg);
        for(int i=0; i < idEvent - 1; ++i){
            //inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');

        }

        std::getline(inFile, line);
        std::vector<std::string> eventInit = StaticFunctions::split(line, ':');
        _name=eventInit[0];
        _display=eventInit[1];
        _event=eventInit[2];
        _gold=std::stoi(eventInit[3]);
        _damage=std::stoi(eventInit[4]);
        _presence=std::stoi(eventInit[5]);
        _loot=std::stoi(eventInit[6]);
    }
    inFile.close();
}
