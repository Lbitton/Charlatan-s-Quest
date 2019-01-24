#include "StaticMonsterTechniques.h"

StaticMonsterTechniques::StaticMonsterTechniques()
{
    //ctor
}

StaticMonsterTechniques::~StaticMonsterTechniques()
{
    //dtor
}

void StaticMonsterTechniques::humanoidBaseAtk(Entity &activeMonster, Player &target){
    activeMonster.dealDamage(target, activeMonster.getAtk(), 1, "physical");
}

void StaticMonsterTechniques::humanoidSlashAtk(Entity &activeMonster, Player &target){
    std::cout << activeMonster.getName() << " slashes twice." << std::endl;
    activeMonster.dealDamage(target, activeMonster.getAtk()+1, 2, "physical");
}


void StaticMonsterTechniques::humanoidBattleSongSpell(Entity &activeMonster, Player &target){
    activeMonster.modifBonusAtk(1);
    target.modifStress(1);
    std::cout << activeMonster.getName() << " yells terrifying hymns of battle. It gains 1 atk and stresses you for 1." << std::endl;
}


void StaticMonsterTechniques::beastPoisonBit(Entity &activeMonster, Player &target){
    activeMonster.dealDamage(target, activeMonster.getAtk()/2, 1, "magical");
   // sans la map target.setStatus(2,2);
    target.modifStatus(2,2); // avec la map
    // poison pour deux tours
    std::cout << activeMonster.getName() << " poisons " << target.getName() << std::endl;
}

void StaticMonsterTechniques::beastCrawl(Entity &activeMonster, Player &target){
   // activeMonster.setStatus(0, 0);    SANS LA MAP
   // activeMonster.clearStatus();      SANS LA MAP
    std::cout << "Crawl clears " << activeMonster.getName() << " from all status effect and allows it to atk." << std::endl;
    activeMonster.dealDamage(target, activeMonster.getAtk()*0.8, 1);
}

void StaticMonsterTechniques::beastIntimidate(Entity &activeMonster, Player &target){
    target.modifBonusDef(-1);
    std::cout << target.getName() << " is intimidate and lose -1 def." << std::endl;
}

void StaticMonsterTechniques::apparitionHaunt(Entity &activeMonster, Player &target){
    target.modifStress(1);
    std::cout << activeMonster.getName() << " whispers. " << target.getName() << " hears it directly in his head. Stress up 1." << std::endl;
}

void StaticMonsterTechniques::apparitionBoilFlesh(Entity &activeMonster, Player &target){
    target.modifLifeActual(-2);
    std::cout << target.getName() << " boils in his armor and takes 2 hp (not reduced by defense)" << std::endl;
}
void StaticMonsterTechniques::apparitionWeakCurse(Entity &activeMonster, Player &target){
    std::cout << target.getName() << " is cursed ! He feels weaken and lose 2 atk" << std::endl;
    target.modifBonusAtk(-1);
}



