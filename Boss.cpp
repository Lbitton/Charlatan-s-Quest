#include "Boss.h"

Boss::Boss()
{
    _EntityName = "Boss";
    _monsterType = "boss";
    _lifeMax = 15;
    _manaMax = 0;
    _lifeActual = _lifeMax;
    _atk = 5;
    _def = 5;
    _resilience = 3;
    _bonusAtk = 0;
    _bonusDef = 0;
  //  _status = 0;
  //  _ctrStatus = 0;
}

Boss::~Boss()
{
    //dtor
}

void Boss::bossATKMenu(Player &player){
    int enemyChoice;
    enemyChoice = rand() %3 +1; //6 + 1;

    if(_EntityName == "Sleeping Giant"){
        switch(enemyChoice){
            case 1:
                StaticBossTechniques::giantSmash(*this, player);
                break;
            case 2:
                StaticBossTechniques::giantBoulderThrow(*this, player);
                break;
            case 3:
                StaticMonsterTechniques::beastIntimidate(*this, player);
                std::cout<<"After yelling, the fiend sits down and closes it's eyes to rest."<<std::endl;
                modifStatus(1, 2);
                heal();
                break;
            default :
                StaticBossTechniques::giantSmash(*this, player);
                break;
        }
    }
    else if(_EntityName == "Mind Flayer"){
        switch(enemyChoice){
            case 1:
                StaticBossTechniques::mindControl(*this, player);
                break;
            case 2:
                StaticBossTechniques::mindSummon(*this, player);
                break;
            case 3:
                if(getLifeActual()<(getLifeMax()/3)){
                    heal();
                }
                StaticMonsterTechniques::humanoidBattleSongSpell(*this, player);
                break;
            default :
                StaticBossTechniques::mindControl(*this, player);
                break;
        }

    }
    else if(_EntityName == "Abyss Watcher"){
        switch(enemyChoice){
            case 1:
                StaticBossTechniques::abyssStrike(*this, player);
                break;
            case 2:
                StaticBossTechniques::abyssDespair(*this, player);
                break;
            case 3:
                StaticMonsterTechniques::humanoidSlashAtk(*this, player);
                break;
            default :
                StaticBossTechniques::abyssStrike(*this, player);
                break;
        }
    }
    else if(_EntityName == "Dominion"){
            switch(enemyChoice){
            case 1:
                StaticBossTechniques::dominionLight(*this, player);
                break;
            case 2:
                StaticBossTechniques::dominionPureStrike(*this, player);
                break;
            case 3:
                StaticMonsterTechniques::apparitionBoilFlesh(*this, player);
                StaticMonsterTechniques::apparitionWeakCurse(*this, player);
                break;
            default :
                StaticMonsterTechniques::apparitionBoilFlesh(*this, player);
                break;
        }
    }
    else if(_EntityName == "Calamity"){
            switch(enemyChoice){
            case 1:
                StaticBossTechniques::calamityDecimate(*this, player);
                break;
            case 2:
                StaticBossTechniques::calamityFeed(*this, player);
                break;
            case 3:
                StaticMonsterTechniques::beastIntimidate(*this, player);
                StaticMonsterTechniques::beastPoisonBit(*this, player);
                break;
            default :
                StaticMonsterTechniques::beastIntimidate(*this, player);
                StaticMonsterTechniques::beastPoisonBit(*this, player);
                break;
        }
    }
    else{
        // Pour les futurs boss
    }
}

void Boss::heal(){
    int heal = rand()%10+1;
    modifLifeActual(heal);
    std::cout<<"The fiend heals itself for "<<heal<<" HP."<<std::endl;
}


void Boss::initBoss(int idBoss){
    std::ifstream inFile;
    inFile.open("Boss_file.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;

        inFile.seekg(std::ios::beg);
        for(int i=0; i < idBoss - 1; ++i){
            //inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');

        }
        std::getline(inFile, line);


        std::vector<std::string> bossInit = StaticFunctions::split(line, ':');

        _EntityName = bossInit[0];
        _initiative = std::stoi(bossInit[1]);
        _lifeMax = std::stoi(bossInit[2]);
        _lifeActual = std::stoi(bossInit[2]);
        _atk = std::stoi(bossInit[3]);
        _def = std::stoi(bossInit[4]);
        _resilience = std::stoi(bossInit[5]);
        _statusMap["stun"] = std::stoi(bossInit[6]);
        _monsterType = bossInit[7];   //Parait superflu
        }
    inFile.close();
}
