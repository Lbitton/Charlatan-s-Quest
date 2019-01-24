#include "Player.h"

Player::Player(): tech1("Attaque de base", 0, 1, 1, 0, 0, "physical"), tech2("SliceNDice", 2, 0.5, 3, 0, 0, "physical"),
    tech3("Bash", 6, 1.5, 1, 1, 1, "physical"), tech4("RandAtk", 0, rand()%18 + 1, rand()%5 + 1, 0, 0, "magical"),
    equipedArmor("Simple Armor",0,1), equipedWeapon("Simple Sword",1,0)
{
    //ctor
    _EntityName = "Player";
    _lifeMax = 30;
    _manaMax = 10;
    _resilience = 0;
    _lifeActual = _lifeMax;
    _manaActual = _manaMax;
    _atk = 4;
    _def = 1;
    _bonusAtk = 0;
    _bonusDef = 0;
   // _status = 0;
   // _ctrStatus = 0;
    _blueprints = 1;
    _detection = 2;
    _stressMax = 10;
    _stress = 0;
    _villageoisFree = 0;
    _inventory["LPotions"] = 3;
    _inventory["MPotions"] = 3;
    _inventory["Keys"] = 1;
    _inventory["Gold"] = 50;
    _inventory["Antidote"]= 1;
}

Player::~Player()
{
    //dtor
}

void Player::deathReset(){
    _stress = 0;
    _inventory["LPotions"] = 3;
    _inventory["MPotions"] = 3;
    _inventory["Keys"] = 1;
    _inventory["Gold"] = 50;
    _inventory["Antidote"]= 1;
    }

void Player::classChoice(){
//1. Expert, 2. Soldier, 3. Fakir, 4. Assassin, 5. Sorcerer, 6. Jester
    int choice;
    std::cout << "Which class would you pick ?" << std::endl << "1. Expert, 2. Soldier, 3. Assassin, 4. Fakir, 5. Sorcerer, 6. Jester" << std::endl;
    std::cin >> choice;
    switch(choice){
        case 1:
            //EXPERT
            tech1.modifTech("Attaque de base", 2, 1, 1, 0, 0, "physical");
            tech2.modifTech("Precise Strike", 3, 2, 1, 0, 0, "physical");
            tech3.modifTech("Headache", 2, 0.5, 1, 2, 2, "physical");
            tech4.modifTech("Eureka !", 10, 0, 0, 0, 0, "");
            modifAtk(1);
            modifManaMax(2);
            modifLifeMax(5);
            _lifeActual = _lifeMax;
            _manaActual = _manaMax;
            changeName("The Expert");
            break;
        case 2:
            //SOLDIER
            tech1.modifTech("Knuckles", 3, 2, 1, 0, 0, "physical");
            tech2.modifTech("", 1, 0.5, 3, 0, 0, "physical");
            tech3.modifTech("Cut", 4, 1, 1, 2, 3, "physical");
            tech4.modifTech("Deathglare", 6, 0, 0, 1, 2, "physical");
            modifAtk(1);
            modifResilience(15);
            modifDef(-1);
            changeName("The Soldier");
            break;
        case 3:
            //ASSASINNE
            tech1.modifTech("SliceNDice", 2, 0.5, 2, 0, 0, "physical");
            tech2.modifTech("Cut", 4, 1, 1, 2, 3, "physical");
            tech3.modifTech("Shadow Daggers", 0, 0, 0, 0, 0, "magical");
            tech4.modifTech("Deathglare", 6, 0, 0, 1, 2, "physical");
            modifDetection(5);
            changeName("The Assassine");
            break;
        case 4:
            tech1.modifTech("Lashes", 1, 0.2, 4, 0, 0, "physical");
            tech2.modifTech("Empale", 2, 2, 2, 0, 0, "physical");
            tech3.modifTech("Rain of whip", 4, 0.6, 1, 2, 2, "physical");
            tech4.modifTech("Revel", 0, 0, 0, 0, 0, "");
            modifLifeMax(10);
            _lifeActual = _lifeMax;
            modifDef(-1);
            changeName("The Fakir");
            break;
        case 5:
            //SORCERER
            tech1.modifTech("Mana drain", 5, 0.2, 1, 0, 0, "physical");
            tech2.modifTech("Fireball", 4, 6, 1, 0, 0, "magical");
            tech3.modifTech("Frostblast", 1, 2, 1, 2, 2, "magical");
            tech4.modifTech("Ice barriere", 3, 0, 0, 0, 0, "magical");
            modifManaMax(5);
            _manaActual = _manaMax;
            changeName("The Sorcerer");
            break;
        case 6:
            //JESTER
            tech1.modifTech("A votre bon vouloir", 10, 0, 1, 0, 0, "physical");
            tech2.modifTech("Gigue", 4, 1, 1, 0, 0, "physical");
            tech3.modifTech("Ballet sanglant", 2, 2, 1, 2, 4, "magical");
            tech4.modifTech("Mis à nu !", 3, 0, 0, 4, 4, "physical");

            switchArmor(12);
            modifLifeMax(-5);
            _lifeActual = _lifeMax;
            changeName("The Jester");
            break;

    }

}

void Player::switchArmor(int idNewArmor){
    _def -= equipedArmor.getEquiBonusDef();
    _atk -= equipedArmor.getEquipBonusAtk();
    // test
   //     std::cout << "-" << equipedArmor.getEquiBonusDef() << " def & -" << equipedArmor.getEquipBonusAtk() << " atk. " << std::endl;
    equipedArmor.changeEquipment(idNewArmor);
    // test
    _def += equipedArmor.getEquiBonusDef();
    _atk += equipedArmor.getEquipBonusAtk();
    //    std::cout << "+" << equipedArmor.getEquiBonusDef() << " def & +" << equipedArmor.getEquipBonusAtk() << " atk. " << std::endl;
    if(_def < 0){
        _def = 0;
    }
    if(_atk < 0){
        _atk = 0;
    }
}

void Player::switchWeapon(int idNewWeapon){
    // test
    _def -= equipedWeapon.getEquiBonusDef();
    _atk -= equipedWeapon.getEquipBonusAtk();
      //  std::cout << "-" << equipedWeapon.getEquiBonusDef() << " def & -" << equipedWeapon.getEquipBonusAtk() << " atk. " << std::endl;
    equipedWeapon.changeEquipment(idNewWeapon);
    // test
    _def += equipedWeapon.getEquiBonusDef();
    _atk += equipedWeapon.getEquipBonusAtk();
      //  std::cout<< equipedWeapon.getEquiBonusDef() << " def & " << equipedWeapon.getEquipBonusAtk() << " atk. " << std::endl;
    if(_def < 0){
        _def = 0;
    }
    if(_atk < 0){
        _atk = 0;
    }
}

int Player::getVillageois(){
    return _villageoisFree;
}

void Player::freeVillageois(){
    std::cout<<"The citizen living in the town Village is now free !"<<std::endl;
    _villageoisFree += 1;
}

void Player::setVillageois(int villageois){
    _villageoisFree = villageois;
}


void Player::displayArmorAndWeapon(){
    equipedArmor.displayE();
    equipedWeapon.displayE();
}

void Player::displayInventory(){
    std::string input;

    std::cout<<std::flush;
    std::cout<<"You open your bag, you have:"<<std::endl;
    std::cout<<_inventory["LPotions"]<<" Life potions | "<<_inventory["MPotions"]<<" Mana Potions | "<<_inventory["Antidote"]<<" Antidotes | "<<_inventory["Keys"]<<" Keys."<<std::endl;
    std::cout<<"And "<<_inventory["Gold"]<<" Gold Coins."<<std::endl;
    std::cout<<"Your status :";
    displayStatus();
    std::cout<<"Would you like to use a potion ?  1.Yes | 2.No"<<std::endl;
    std::cin>>input;
    if(input == "1"){
        usePotion();
    }
    else{
        std::cout<<"You've decided to save the potions for a better occasion. It will surely be more useful later."<<std::endl;
    }
}

// Pour test
void Player::displayStatus(){
    std::cout << "HP: " << _lifeActual << "/" << _lifeMax << ", Resilience: " << _resilience << ", Mana: " << _manaActual << "/" << _manaMax << std::endl;
}

// Pour test
void Player::displayAtkDef(){
    std::cout << "Atk : " << _atk << ". Def :" << _def << "." << std::endl;
}

void Player::choiceMenu(Entity &cible){
    std::string choice;
    std::cout << "What do you do ? " << std::endl << "1. Attack ? 2. Use item ? 3. Display Stat ?" << std::endl;
    std::cin >> choice;
    if(choice == "1"){
        atkMenu(cible);
    }else if(choice == "2"){
        displayInventory();
    }else if(choice == "3"){
        std::cout << _EntityName << " has " << _lifeActual << "/" << _lifeMax << " hp and " << _manaActual << "/" << _manaMax << " mana" << std::endl;
        std::cout << _EntityName << " has " << _resilience << " resilience left. " << _atk << " atk & " << _def << " def." << std::endl;
        std::cout << _EntityName << "'s equipment : " << std::endl;
        equipedArmor.displayE();
        equipedWeapon.displayE();
        choiceMenu(cible);
    }else{
        std::cout << "Invalid choice" << std::endl;
        choiceMenu(cible);
    }
}

void Player::atkMenu(Entity &target){
    int choix;

    std::cout << std::flush;
    //OLD VERSION : std::cout << "1. Atk de base (dgt *1) | 2. SliceNDice (dgt/2 * 3) | 3. Bash(dgt*1.5) | 4. randAtk(r,r)" << std::endl;
    std::cout << "1. " << tech1.getAtkName()/* << " (" << tech1.getAtkNbr() << " * " << _atk*tech1.getAtkStrenght() */ << " (for " << tech1.getManaCost()
        << "). | 2. " << tech2.getAtkName() << " (" << tech2.getAtkNbr() << " * " << _atk*tech2.getAtkStrenght() << " (for " << tech2.getManaCost()
        << "). | 3. " << tech3.getAtkName() << " (" << tech3.getAtkNbr() << " * " << _atk*tech3.getAtkStrenght() << " (for " << tech3.getManaCost()
        << "). | 4. " << tech4.getAtkName() << " (" << tech4.getAtkNbr() << " * " << _atk*tech4.getAtkStrenght() << " (for " << tech4.getManaCost()
        << ")." << std::endl;

    std::cin >> choix;
    while(choix != 1 && choix != 2 && choix != 3 && choix !=4){
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << std::flush;
        std::cout << "Invalid input." << std::endl;
        std::cin >> choix;
    }

    switch(choix){
        case 1:
                tech1.UseOffTechnique(*this, target);
                // attaque de base rend de la mana au lieu d'en couter.
                modifManaActual(tech1.getManaCost()*tech1.getAtkNbr());
                std::cout << tech1.getAtkName() << " gives " << tech1.getManaCost()*tech1.getAtkNbr() << " mana to the " << _EntityName << std::endl;
            break;
        case 2:
            if(tech2.getManaCost() <= _manaActual){
                tech2.UseOffTechnique(*this, target);
                modifManaActual(-tech2.getManaCost());
            }else{
                std::cout << "Not enough mana !" << std::endl;
                atkMenu(target);
            }
            break;
        case 3:
            if(tech3.getManaCost() <= _manaActual){
                tech3.UseOffTechnique(*this, target);
                modifManaActual(-tech3.getManaCost());
            }else{
                std::cout << "Not enough mana !" << std::endl;
                atkMenu(target);
            }
            break;
        case 4:
            if(tech4.getManaCost() <= _manaActual){
               tech4.UseOffTechnique(*this, target);
               modifManaActual(-tech4.getManaCost());
            }else{
                std::cout << "Not enough mana !" << std::endl;
                atkMenu(target);
            }
            break;
        default:
                tech1.UseOffTechnique(*this, target);
                modifManaActual(tech1.getManaCost()*tech1.getAtkNbr());
            break;
    }
    // OLD VERSION : monster.displayMonster();
    std::cout << std::endl;
}

void Player::usePotion(){
    std::string input;
    std::cout<<std::flush;
    std::cout<<"Which potion would you like to use ?"<<std::endl;
    std::cout<<"1.Life Potion("<<getLifePotions()<<") [+30%] | 2.Mana Potion("<<getManaPotions()<<") [+30%] | 3.Antidote("<<getAntidotes()<<") [Cure] | 4.Nevermind"<<std::endl;
    std::cin>>input;
    if(input=="1"){
        std::cout<<"You've used a life potion. You've restored half of your maximum life"<<std::endl;

        modifLifeActual(getLifeMax()/3);
        if(equipedArmor.getSpecialBonus() == 2 || equipedWeapon.getSpecialBonus() == 2){
            modifLifeActual(getLifeMax()/3);
        }

        modifLifePotion(-1);
        std::cout<<"You now have "<<getLifeActual()<<" life points and "<<getLifePotions()<<" potions remaining."<<std::endl;
    }
    else if(input=="2"){
        std::cout<<"You've used a mana potion. You've restored half of your max mana"<<std::endl;
        modifManaActual(getManaMax()/3);
        if(equipedArmor.getSpecialBonus() == 2 || equipedWeapon.getSpecialBonus() == 2){
            modifManaActual(getLifeMax()/3);
        }
        modifManaPotion(-1);
        std::cout<<"You now have "<<getManaActual()<<" mana points and "<<getManaPotions()<<" potions remaining."<<std::endl;
    }
    else if(input == "3"){
        //std::cout<<"UNDER CONSTRUCTION"<<std::endl;
        _statusMap["poison"] = 0;
        _statusMap["bleed"] = 0;
        _statusMap["stun"] = 0;

        modifAntidote(-1);
        std::cout<<"You are now cured of any disease and have "<<getAntidotes()<<" antidotes left."<<std::endl;
    }
    else if(input=="4"){
        std::cout<<"You have changed your mind"<<std::endl;
    }
    else{
        std::cout<<"Invalid choice."<<std::endl;
        usePotion();
    }
}

void Player::stressAtMax(){
    if(_stress == _stressMax){
        std::cout << "You're going to die here. You know it ! Stressed : -1hp !";
        _lifeActual--;
    }
}



int Player::getGold(){
    return _inventory["Gold"];
}

void Player::modifGold(int gold){
    _inventory["Gold"] += gold;
}

int Player::getLifePotions(){
    return _inventory["LPotions"];
}

void Player::modifLifePotion(int lifePotion){
    _inventory["LPotions"] += lifePotion;
}

int Player::getManaPotions(){
    return _inventory["MPotions"];
}

void Player::modifManaPotion(int manaPotion){
    _inventory["MPotions"] += manaPotion;
}

int Player::getKeys(){
    return _inventory["Keys"];
}
void Player::modifKeys(int keys){
    _inventory["Keys"] += keys;
}
int Player::getAntidotes(){
    return _inventory["Antidote"];
}
void Player::modifAntidote(int antidote){
    _inventory["Antidote"] += antidote;
}

int Player::getBlueprints(){
    return _blueprints;
}

void Player::modifBluePrints(int newBluePrints){
    _blueprints += newBluePrints;
    if(_blueprints < 0){
        _blueprints = 0;
    }
}

int Player::getStress(){
    return _stress;
}

int Player::getStressMax(){
    return _stressMax;
}

void Player::modifStress(int stressModif){
   _stress += stressModif;
   if(_stress > _stressMax){
     _stress = _stressMax;
   }else if(_stress < 0){
    _stress = 0;
   }
}

int Player::getDetection(){
    return _detection;
}

void Player::modifDetection(int detectmodif){
    _detection += detectmodif;
    if(_detection < 0){
        _detection = 0;
    }
}

int Player::getWeaponSpecial(){
    return equipedWeapon.getSpecialBonus();
}

int Player::getArmorSpecial(){
    return equipedArmor.getSpecialBonus();
}

