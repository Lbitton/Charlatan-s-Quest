#include "Monster.h"

Monster::Monster()
{
    //ctor
    _EntityName = "Monster";
    _monsterType = "monster";
    _lifeMax = 1;
    _manaMax = 0;
    _lifeActual = _lifeMax;
    _atk = 1;
    _def = 1;
    _resilience = 0;
    _bonusAtk = 0;
    _bonusDef = 0;
   // _status = 0;
   // _ctrStatus = 0;
}



Monster::~Monster()
{
    //dtor
}
/*
void Monster::displayMonster(){
    std::cout << _EntityName << " a encore " << _lifeActual << " pv" << std::endl;
}*/

void Monster::monsterATKmenu(Player &target){
    int enemyChoice;
    enemyChoice = rand() %3 +1; //6 + 1;

    if(_monsterType == "Humanoid"){
        switch(enemyChoice){
            case 1:
                StaticMonsterTechniques::humanoidBaseAtk(*this, target);
                break;
            case 2:
                StaticMonsterTechniques::humanoidSlashAtk(*this, target);
                break;
            case 3:
                StaticMonsterTechniques::humanoidBattleSongSpell(*this, target);
                break;
            default :
                StaticMonsterTechniques::humanoidBaseAtk(*this, target);
                break;
        }
    }else if(_monsterType == "Beast"){
        switch(enemyChoice){
            case 1:
                StaticMonsterTechniques::beastPoisonBit(*this, target);
                break;
            case 2:
                StaticMonsterTechniques::beastCrawl(*this, target);
                break;
            case 3:
                StaticMonsterTechniques::beastIntimidate(*this, target);
                break;
            default :
                StaticMonsterTechniques::beastPoisonBit(*this, target);
                break;
        }

    }else if(_monsterType == "Apparition"){
        switch(enemyChoice){
            case 1:
                StaticMonsterTechniques::apparitionHaunt(*this, target);
                break;
            case 2:
                StaticMonsterTechniques::apparitionBoilFlesh(*this, target);
                break;
            case 3:
                StaticMonsterTechniques::apparitionWeakCurse(*this, target);
                break;
            default :
                StaticMonsterTechniques::apparitionHaunt(*this, target);
                break;
        }
    }else{
        // Si d'autres types de monstre ou un par defaut;
    }
}

void Monster::initMonster(int idMonster){
    std::ifstream inFile;
    inFile.open("Monster_file.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;

        inFile.seekg(std::ios::beg);
        for(int i=0; i < idMonster - 1; ++i){
            //inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');

        }
        std::getline(inFile, line);


        std::vector<std::string> monsterInit = StaticFunctions::split(line, ':');

        _EntityName = monsterInit[0];
        _initiative = std::stoi(monsterInit[1]);
        _lifeMax = std::stoi(monsterInit[2]);
        _lifeActual = std::stoi(monsterInit[2]);
        _atk = std::stoi(monsterInit[3]);
        _def = std::stoi(monsterInit[4]);
        _resilience = std::stoi(monsterInit[5]);
        //_status = std::stoi(monsterInit[6]); // old version
        //_ctrStatus = std::stoi(monsterInit[7]); // old version
        _statusMap["stun"] = std::stoi(monsterInit[7]);
        _monsterType = monsterInit[8];
        }
    inFile.close();
}

void Monster::changeInitiative(int newInitiative){
    _initiative = newInitiative;
}

int Monster::getInitiative(){
    return _initiative;
}

std::string Monster::getMonsterType(){
    return _monsterType;
}

