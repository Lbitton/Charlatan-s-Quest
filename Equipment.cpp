#include "Equipment.h"

Equipment::Equipment()
{
    //ctor
}

Equipment::~Equipment()
{
    //dtor
}


void Equipment::initEquipment(int idEquip, int type){
    std::vector<std::string> initEquip = readEquipmentFile(idEquip, type);
    _equipmentName = initEquip[0];
    _bonusAtk = std::stoi(initEquip[1]);
    _bonusDef = std::stoi(initEquip[2]);
    _price = std::stoi(initEquip[3]);
    _specialBonus = std::stoi(initEquip[4]);
    _equipmentDescription = initEquip[5];
    //std::cout << "test : name : " << _equipmentName << " bonusAtk: " << _bonusAtk << " bonusDef: " << _bonusDef << std::endl;

}

std::vector<std::string> Equipment::readEquipmentFile(int idEquip, int type){
    std::ifstream inFile;
    if(type == 0){
        inFile.open("Armor_file.txt");
    }else if(type == 1){
        inFile.open("Weapon_file.txt");
    }

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;

        inFile.seekg(std::ios::beg);
        for(int i=0; i < idEquip - 1; ++i){
        //    inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');
        }
        std::getline(inFile, line);

        std::vector<std::string> readEquip = StaticFunctions::split(line, ':');
        inFile.close();
        return readEquip;
    }
}

void Equipment::changeEquipment(int newID){
    initEquipment(newID, _type);
}

// POUR TEST
void Equipment::displayE(){
    std::cout << _equipmentName << " : " << _bonusAtk << " atk & " << _bonusDef << " def" << std::endl;
    std::cout << _equipmentDescription << std::endl;
}

int Equipment::getPrice(){
    return _price;
}

int Equipment::getEquipBonusAtk(){
    return _bonusAtk;
}

int Equipment::getEquiBonusDef(){
    return _bonusDef;
}

std::string Equipment::getName(){
    return _equipmentName;
}

std::string Equipment::getDescription(){
    return _equipmentDescription;
}

int Equipment::getSpecialBonus(){
    return _specialBonus;
}
