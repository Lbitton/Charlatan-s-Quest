#include "Rooms.h"

Rooms::Rooms()
{
    _explorationLVLDanger = 0; //Sinon, rencontre avec boss dès le début du jeu
}

Rooms::~Rooms()
{
    //dtor
}

std::vector<std::string> Rooms::readRoomFile(int idRoom){
    std::ifstream inFile;
    inFile.open("Room_file.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;
        inFile.seekg(std::ios::beg);
        for(int i=0; i < idRoom - 1; ++i){
            inFile.ignore(1000,'\n');
        }
        std::getline(inFile, line);

        std::vector<std::string> readRoom = StaticFunctions::split(line, ':');
        inFile.close();
        return readRoom;
    }
}

void Rooms::initRoom(int idRoom){
    std::vector<std::string> roomInit = readRoomFile(idRoom);

    _roomName = roomInit[0];
    _roomType = std::stoi(roomInit[1]);
    _levelDanger = std::stoi(roomInit[2]);
    _ifRest = std::stoi(roomInit[3]);
    _nbrEnemy = std::stoi(roomInit[4]);
    _isThereVillageois = std::stoi(roomInit[5]);
    _idSearch = std::stoi(roomInit[6]);
    _ifScout = std::stoi(roomInit[7]);
    _nbrPaths = std::stoi(roomInit[8]);

}

void Rooms::enterRoom(Player &player){
    _explorationLVLDanger += _levelDanger;
    int isThereBoss = rand()%5+1;
    _boss.initBoss(isThereBoss);
    if(player.getWeaponSpecial() == 3 || player.getArmorSpecial() == 3){
        // si armure de peau ou autre, stress au maximum à chaque pièce.
        if(player.getStress() < player.getStressMax()){
            std::cout << "The skincloak maxes your stress." << std::endl;
            player.modifStress(player.getStressMax()-player.getStress());
        }
        //formule vu que les modifs sont en +=;
    }

    std::cout << "You enter " << _roomName << std::endl;
    if(_explorationLVLDanger>20 && isThereBoss>3){
        std::cout<<"You feel something is not right..."<<std::endl;
        Combat bossFight;
        bossFight.bossFight(player, _boss);
        int blueprintsGained = rand()%4+1;
        player.modifBluePrints(blueprintsGained);
        std::cout<<"When you searched the fiend's body, you've found "<<blueprintsGained<<" Blueprints"<<std::endl;
        _explorationLVLDanger = 0;
    }
    else{
        if(_roomType == 0){
            std::cout << "It appears empty" << std::endl;
            //Salle vide
        }else if(_roomType == 1){
            //shrine
            Shrine autel;
            autel.initShrine(player);
        }else if(_roomType == 2){
            std::cout << "A treasure room !" << std::endl;
            //coffre
            int idLoot = rand()%20 + 1;
            Loot loot;
            loot.initLoot(idLoot);
            loot.collect(player);
        }else if(_roomType == 3){
            //ennemi !
            Combat c;
            std::cout << "Ready yourself, a fight has begun !" << std::endl;
            if(_explorationLVLDanger<=10){
                _monster1.initMonster(rand()%15 + 1); // Mobs de base
            }
            else{
                _monster1.initMonster(rand()%25 + 1); //Mobs de base + champions
            }
            if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                _monster1.changeInitiative(1);
            }
            if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                _monster1.changeInitiative(0);
            }

            if(_nbrEnemy == 1){
                c.fightControl(player, _monster1);
            }else if(_nbrEnemy == 2){
                if(_explorationLVLDanger<=10){
                    _monster2.initMonster(rand()%15 + 1); // Mobs de base
                }
                else{
                    _monster2.initMonster(rand()%25 + 1); //Mobs de base + champions
                }
                if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                    _monster2.changeInitiative(1);
                }
                if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                    _monster2.changeInitiative(0);
                }
                c.fightControl2Enemy(player, _monster1, _monster2);
            }else{
                if(_explorationLVLDanger<=10){
                    _monster2.initMonster(rand()%15 + 1); // Mobs de base
                    _monster3.initMonster(rand()%15 + 1);
                }
                else{
                    _monster2.initMonster(rand()%25 + 1); //Mobs de base + champions
                    _monster3.initMonster(rand()%25 + 1);
                }
                if(player.getWeaponSpecial() == 5 || player.getArmorSpecial() == 5){
                // heavy armor, all ennemy have initiative
                    _monster2.changeInitiative(1);
                    _monster3.changeInitiative(1);
                }
                if(player.getWeaponSpecial() == 6 || player.getArmorSpecial() == 6){
                // feather armor, all ennemy lose initiative
                    _monster2.changeInitiative(0);
                    _monster3.changeInitiative(0);
                }
                c.fightControl3Enemy(player, _monster1, _monster2, _monster3);
                player.modifBluePrints(1);
                std::cout<<"You've found 1 blueprint on one of the dead bodies"<<std::endl;
            }
        }else if(_roomType == 4){
            int merchantType = rand()%2;  //If ==0 Equipement, if ==1 Items ?
            if(merchantType == 1){
                ItemMerchant merchant;
                merchant.encounter(player);
            }
            else if(merchantType == 0){
                EquipementMerchant merchant;
                merchant.encounter(player);
            }
        }
    }
    if(player.isAlive()){
        if(_isThereVillageois == 1){
            player.freeVillageois();
        }
        choicePostRoom(player);
        enterRoom(player);
    }
}

void Rooms::choicePostRoom(Player &player){
    int choice;
    std::cout<< "You can 1. Rest (heal for " << _ifRest << "hp), 2. Search for loot or 3. Scout ahead" << std::endl;
    std::cin >> choice;

    if(choice == 3){
        //scouting => bonus à la detection de la salle suivante
        nextRoomChoice(player.getDetection()+3, _nbrPaths);
    }else if(choice == 1){
        // repos
        player.modifLifeActual(_ifRest);
        std::cout << "You rested you weary soul and gained " << _ifRest << " hp." << std::endl;
        if(_roomType == 0 && player.getStress()>0){
            // si la pièce est  vide, se reposer diminue le stress du joueur de 1.
            player.modifStress(-1);
            std::cout << "The emptiness of the room calms your nerves. Stress -1" << std::endl;
        }else if(_roomType == 1 && player.getStress()>0){
            // si la pièce est un autel, se reposer diminue le stress du joueur de 3.
            player.modifStress(-3);
            std::cout << "The gods have not forsaken you. Stress -3";
        }
        nextRoomChoice(player.getDetection(), _nbrPaths);
    }else if(choice == 2){
        int chanceLoot = rand()%2;
        if(chanceLoot==1){
            int idLoot = rand()%10 + 1;
            Loot loot;
            loot.initLoot(idLoot);
            loot.collect(player);
        }
        else{
            std::cout<<"You have searched everywhere, and haven't found anything but the crushing silence in this room. You've wasted enough time. Move on now."<<std::endl;
        }
        nextRoomChoice(player.getDetection(), _nbrPaths);
    }


    Event event;
    event.execute(player);
}

void Rooms::nextRoomChoice(int scout, int nbrPath){
    int room1 = rand()%30 + 1;
    int room2 = rand()%30 + 1;
    int choice;

    switch(nbrPath){
        case 1:
            std::cout << "You can only see one door." << std::endl;
            std::cout << "Not much choice" << std::endl << "1. ";
            scoutRoom(scout, room1);
            std::cin >> choice;
            initRoom(room1);
            break;
        case 2:
            std::cout << "You see two doors" << std::endl;
            std::cout << "1. ";
            scoutRoom(scout, room1);
            std::cout << "2. ";
            scoutRoom(scout, room2);
            std::cin >> choice;
            if(choice == 1){
                initRoom(room1);
            }else{
                initRoom(room2);
            }
            break;
        case 3:
            int room3 = rand()%7 + 1;
            std::cout << "You see three doors" << std::endl;
            std::cout << "1. ";
            scoutRoom(scout, room1);
            std::cout << "2. ";
            scoutRoom(scout, room2);
            std::cout << "3. ";
            scoutRoom(scout, room3);
            std::cin >> choice;
            if(choice == 1){
                initRoom(room1);
            }else if(choice == 2){
                initRoom(room2);
            }else{
                initRoom(room3);
            }
            break;
    }

}

void Rooms::scoutRoom(int scout, int idNewRoom){
    std::vector<std::string> scoutedRoom = readRoomFile(idNewRoom);

   // déterminer les displays des infos des salles suivantes
   // dans l'ordre nom / niveau de danger / nbr ennemi // si villageois
    int canScout = (rand()%4 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout2 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout3 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;
    int canScout4 = (rand()%7 + 1) + stoi(scoutedRoom[7]); //malusScoutRoom;

    if(scout >= canScout){
        std::cout << scoutedRoom[0] << "| ";
    }else{
        std::cout <<"??? ";
    }
        if(scout >= canScout2){
        std::cout<< std::stoi(scoutedRoom[2]) << " de danger| ";
    }else{
        std::cout <<"??? ";
    }
        if(scout >= canScout3){
        std::cout << stoi(scoutedRoom[4]) << "ennemis| ";
    }else{
        std::cout <<"???? ";
    }
        if(scout >= canScout4){
            if(stoi(scoutedRoom[5]) == 0){
                std::cout << "Pas de villageois." << std::endl;
            }else{
                std::cout << "Il y a un villageois !" << std::endl;
            }
    }else{
        std::cout<< "???" << std::endl;
    }
}

void Rooms::displayRoom(){
    std::cout<<_roomName<<_roomType<<_levelDanger<<_ifRest<<_nbrEnemy<<_isThereVillageois<<_idSearch<<_ifScout<<_nbrPaths<<_idRoom<<std::endl;
}
