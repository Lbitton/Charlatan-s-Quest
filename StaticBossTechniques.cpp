#include "StaticBossTechniques.h"

StaticBossTechniques::StaticBossTechniques()
{
    //ctor
}

StaticBossTechniques::~StaticBossTechniques()
{
    //dtor
}

void StaticBossTechniques::giantSmash(Entity &currentBoss, Player &player){
    int  behind= rand()%2;
    if(behind==0){
        std::cout<<"The giant charges straight towards you."<<std::endl;
        currentBoss.dealDamage(player, currentBoss.getAtk(), 1, "physical");
    }
    else{
        std::cout<<"You managed to get behind the giant, buying yourself some extra time."<<std::endl;
    }
}

void StaticBossTechniques::giantBoulderThrow(Entity &currentBoss, Player &player){
    int  behind= rand()%2;
    if(behind==0){
        std::cout<<"The giant throws a large boulder in your direction."<<std::endl;
        int esquive = rand()%100+1;
        if(esquive>50){
            std::cout<<"You've managed to roll on the side"<<std::endl;
        }
        currentBoss.dealDamage(player, currentBoss.getAtk()+5, 1, "physical");
    }
    else{
        std::cout<<"You managed to get behind the giant, buying yourself some extra time."<<std::endl;
    }
}

void StaticBossTechniques::mindControl(Entity &currentBoss, Player &player){
    std::cout<<"The Mind Flayer took control of your body. It forces you to attack yourself"<<std::endl;
    std::cout<<player.getAtk()<<" hp lost. 2 stress gained."<<std::endl;
    player.modifLifeActual(-player.getAtk());
    player.modifStatus(1,2);
    player.modifStress(2);
}

void StaticBossTechniques::mindSummon(Entity &currentBoss, Player &player){
    std::cout<<"The Silhouette summons a lesser henchman, and disappears into the darkness"<<std::endl;
    int damage = rand()%10;
    std::cout<<damage<<" damage taken"<<std::endl;
    player.modifLifeActual(-damage);
    std::cout<<"The Mind Flayer emerges once again from the darkness"<<std::endl;
}

void StaticBossTechniques::abyssStrike(Entity &currentBoss, Player &player){
    int strikes = rand()%3 +1;
    std::cout<<"The Watcher unleashed a series of strikes with his black sword"<<std::endl;
    currentBoss.dealDamage(player, currentBoss.getAtk(), strikes, "physical");
    std::cout<<"Stress +1 per strike"<<std::endl;
    player.modifStress(strikes*1);
    player.modifStatus(2, 3);
}

void StaticBossTechniques::abyssDespair(Entity &currentBoss, Player &player){
    std::cout<<"The Watcher projects black Ooze on you"<<std::endl;
    currentBoss.dealDamage(player, currentBoss.getAtk(), 1, "magical");
    std::cout<<"Stress +2"<<std::endl;
    player.modifStress(2);
    int poison = rand()%2;
    if(poison == 1){
        std::cout<<"You have been poisoned !"<<std::endl;
        player.modifStatus(3, 2);
    }
}

void StaticBossTechniques::dominionLight(Entity &currentBoss, Player &player){
    std::cout<<"The Dominion opens it's eyes, radiant light blinds you. Stunned for the next."<<std::endl;
    player.modifStatus(1, 2);
}


void StaticBossTechniques::dominionPureStrike(Entity &currentBoss, Player &player){
    int strikes = rand()%2+1;
    std::cout<<"Dominion strikes "<<strikes<<" times."<<std::endl;
    currentBoss.dealDamage(player, currentBoss.getAtk(), strikes, "magical");
}

void StaticBossTechniques::calamityDecimate(Entity &currentBoss, Player &player){
    std::cout<<"The Calamity roars and charges"<<std::endl;
    currentBoss.dealDamage(player, currentBoss.getAtk()+5, 1, "physical");
    std::cout<<"Stress +3"<<std::endl;
    player.modifStress(3);
}

void StaticBossTechniques::calamityFeed(Entity &currentBoss, Player &player){
    int heal = rand()%3 +2;
    std::cout<<"The Calamity plunges it's fangs deeply in your skin"<<std::endl;
    currentBoss.dealDamage(player, currentBoss.getAtk(), 1, "physical");
    std::cout<<"It heals itself for"<<heal<<" HP."<<std::endl;
    currentBoss.modifLifeActual(heal);
}
