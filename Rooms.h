#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <iostream>
#include <fstream>

/* Sleep non fonctionnel
#include <stdlib.h>
#include <unistd.h>
*/

#include "StaticFunctions.h"
#include "Player.h"
#include "Combat.h"
#include "Monster.h"
#include "Shrine.h"
#include "Loot.h"
#include "ItemMerchant.h"
#include "EquipementMerchant.h"
#include "Event.h"
#include "Boss.h"

class Rooms
{
    public:
        Rooms();
        ~Rooms();

        std::vector<std::string> readRoomFile(int idRoom);
        void initRoom(int idRoom);
        void enterRoom(Player &player);
        void choicePostRoom(Player &player);
        void nextRoomChoice(int scout, int nbrPath);
        void scoutRoom(int scout, int idNewRoom);
        void displayRoom(); //Pour test

    private:
        std::string _roomName;
        int _roomType;
        int _levelDanger;
        int _ifRest; // vie rendu quand rest dans cette piece
        int _nbrEnemy;
        int _isThereVillageois; // et oui, VILLAGEOIS !
        int _idSearch;
        int _ifScout;
        int _nbrPaths;
        int _idRoom;
        int _explorationLVLDanger;

        Boss _boss;
        Monster _monster1;
        Monster _monster2;
        Monster _monster3;
};


#endif ROOMS_H
