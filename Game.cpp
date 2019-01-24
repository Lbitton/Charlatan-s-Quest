#include "Game.h"
#include <unistd.h>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::introduction(Player &player){
    //Sera faite avec un fichier, evidemment
    Monster intro;
    Combat introFight;
    std::ifstream fichier("PaulEdideAsciii.txt");
    if(fichier){
        std::string ligne;
        while(std::getline(fichier, ligne)){
            std::cout<<ligne<<std::endl;
            usleep(100000);
        }
        fichier.close();
    }
    else{
        std::cout<<"F not found"<<std::endl;
    }
    std::cout<<"As you enter the tavern you usually visit, in search for work, you are halted by a rich looking man"<<std::endl;
    std::cout<<"\"You must be the one they all talk about ! \" says the man. \" I am known in these lands as the Charlatan. They say you are looking for work eh ?\""<<std::endl;
    std::cout<<"You nod, smelling gold nearby as you gaze upon the smooth clothing on that man"<<std::endl;
    std::cout<<"\"Ah, then allow me to explain my situation. You see, I know a village nearby, so swarmed by demons and impure beings that it has been completely destroyed. I, being generous and benevolent, am asking you to go there, free the citizen entrapped in the nearest dungeon and help them rebuild their city, Village. You will be handsomely rewarded, I promise\""<<std::endl;
    std::cout<<"You nod again."<<std::endl;
    std::cout<<"\"Wonderful ! And, like they say in my country \"Ca marche !\" Heh heh. Let's celebrate then, my friend ! Heh heh heh heh....\""<<std::endl;
    std::cout<<"You notice the man's strange laugh, but decide to brush it off when he hands you a glass filled with liquor. You take a big gulp, then another, things get blurry, you keep on drinking, until you find yourself in a field, alone."<<std::endl;
    std::cout<<"You've found a mysterious note in your pocket after you've awakened."<<std::endl;
    std::cout<<"\"Go to the dungeon, free the citizen, and uncover the truth. I am waiting, stranger.\" with the charlatan's name at the bottom of the page."<<std::endl;
    std::cout<<"You arrive in town, and gaze upon a desolated and sad sight"<<std::endl;
    std::cout<<"Listening to your heart only, you decide to acknowledge what the Charlatan said, and to delve deep into the nearby sinister dungeon."<<std::endl;
    //sleep(2);
    std::cout<<"After a few hours on foot, you find yourself in front of a massive black door. It is covered in ancient runic inscriptions and as you set foot onward, it opens just a bit, as if it was waiting for your arrival."<<std::endl;
    std::cout<<"You nervously enter the dungeon. As your eyes go from right to left to assert the danger, a shadow moves in from behind to attack you"<<std::endl;
    //sleep(2);
    std::cout<<"It is time for you to fight, and to test your might."<<std::endl;
    std::cout<<"(In this game, you input your attacks by entering the right numerical value."<<std::endl;
    //sleep(2);
    std::cout<<"Here, try on that fella)"<<std::endl;
    std::cout<<std::endl;
    introFight.fightControl(player, intro);
    std::cout<<std::endl;
    //sleep(2);
    std::cout<<"Congratulations, your first victory, perhaps is it the first stone of a mountain ?"<<std::endl;
    std::cout<<"Before you proceed, you realize the dead foe had a glowing green potion. (You are fully healed)"<<std::endl;
    std::cout<<"You have also found 1 Blueprint. (Those can be useful to upgrade the nearby city, and get lots of stats boosts)"<<std::endl;
    player.modifLifeActual(player.getLifeMax());
    std::cout<<std::endl;
    //sleep(2);
}

void Game::maingame(Player &player, Building &forge, Building &academy, Building &hospital, Building &sanctuary){
    Rooms room;
 //   std::string input;
    std::cout<<"There you are, looking at the entrance of the city Village, eager to begin the adventure the apparently famous Charlatan sent you on."<<std::endl;
    player.classChoice();
    upgradeTown(player, forge, academy, hospital, sanctuary);
    std::cout<<"After the hard work, you have decided to go to the dungeon's first room"<<std::endl;
    room.initRoom(1); //Sinon la 1ere Room n'est jamais initialisee
    while(player.isAlive()){
        room.enterRoom(player);
        if(!player.isAlive()){
                std::cout << player.getName() << " dies alone in a dark cold place." << std::endl;
                std::cout << "Thank goodness, the Charlatan has found someone else to help the Village !" << std::endl;
                checkVillageois(player, academy, hospital, sanctuary);
               // pour test: player.modifBluePrints(2);
                player.modifLifeActual(player.getLifeMax());
                player.deathReset();
                maingame(player, forge, academy, hospital, sanctuary);
        }
    }
}

void Game::upgradeTown(Player &player, Building &forge, Building &academy, Building &hospital, Building &sanctuary){
    int input;
    std::cout << std::endl;
    forge.displayBuilding();
    academy.displayBuilding();
    hospital.displayBuilding();
    sanctuary.displayBuilding();
    std::cout<<"You currently have "<<player.getBlueprints()<<" Blueprints."<<std::endl;
    std::cout<<"Upgrade:"<<std::endl;

    std::cout<<"1.Forge | 2.Academy";
    if(academy.getLvl() == 0) { std::cout << "(locked)";}
    std::cout << "| 3.Hospital";
    if(hospital.getLvl() == 0) { std::cout <<"(locked)";}
    std::cout << "| 4.Sanctuary";
    if(sanctuary.getLvl() == 0) { std::cout <<"(locked)";}
    std::cout << "| 5.Nothing"<<std::endl;

    std::cin>>input;
    std::cout<<std::endl;
    while(input != 1 && input != 2 && input!= 3 && input != 4 && input != 5){
        std::cout<<"Let's do it again..."<<std::endl;
        std::cout<<"1.Forge | 2.Academy | 3.Hospital | 4.Sanctuary | 5.Nothing"<<std::endl;
        std::cout<<std::flush;
        std::cin>>input;
    }
    if(input == 1){
        if(!forge.upgrade(player)){
            upgradeTown(player, forge, academy, hospital, sanctuary);
            /* Si le joueur décide de ne pas améliorer le bâtiment actuel,
            renvoie la fonction à nouveau pour laisser le choix d'améliorer
            un autre bâtiment.
            Si vrai, bâtiment choisi amélioré et le jeu continue.
            */
        }
    }
    else if(input == 2){
        if(academy.getLvl()>0){
            if(!academy.upgrade(player)){
                upgradeTown(player, forge, academy, hospital, sanctuary);
            }
        }else{
            std::cout << "This building is locked. You cannot upgrade it" << std::endl;
            upgradeTown(player, forge, academy, hospital, sanctuary);
        }
    }
    else if(input == 3){
        if(hospital.getLvl() > 0){
            if(!hospital.upgrade(player)){
                upgradeTown(player, forge, academy, hospital, sanctuary);
            }
        }else{
            std::cout << "This building is locked. You cannot upgrade it" << std::endl;
            upgradeTown(player, forge, academy, hospital, sanctuary);
        }
    }
    else if(input == 4){
        if(sanctuary.getLvl()>0){
            if(!sanctuary.upgrade(player)){
                upgradeTown(player, forge, academy, hospital, sanctuary);
            }
        }else{
            std::cout << "This building is locked. You cannot upgrade it" << std::endl;
            upgradeTown(player, forge, academy, hospital, sanctuary);
        }
    }
    else{
        std::cout<<"You have decided to keep those precious blueprints for a better occasion."<<std::endl;
    }
    std::cout<<std::endl;

}

void Game::checkVillageois(Player& player, Building &academy, Building &hospital, Building &sanctuary){
    if(player.getVillageois()>0){
        bool upgraded = false;
        while(player.getVillageois()>0){
            while(upgraded != true){
                int buildingNo = rand()%3;
                if(buildingNo==0 && academy.getLvl()==0){
                    academy.modifLvl(1);
                    std::cout<<"The Villageois you've freed has opened the training academy ! You should check it out !"<<std::endl;
                    upgraded = true;
                }
                else if(buildingNo==1 && hospital.getLvl()==0){
                    hospital.modifLvl(1);
                    std::cout<<"The Villageois you've freed has opened a hospital ! You should check it out !"<<std::endl;
                    upgraded = true;
                }
                else if(buildingNo==2 && sanctuary.getLvl()==0){
                    sanctuary.modifLvl(1);
                    std::cout<<"The Villageois you've freed has opened an obscure sanctuary ! You should check it out !"<<std::endl;
                    upgraded = true;
                }
                else if(academy.getLvl()>0 && hospital.getLvl()>0 && sanctuary.getLvl()>0){
                    int goldgained = rand()%300;
                    std::cout<<"One of the villageois you've helped brings you his family savings. You earned "<<goldgained<<" coins."<<std::endl;
                    player.modifGold(goldgained);
                    upgraded = true;
                }
            }
            player.setVillageois(player.getVillageois()-1);
        }
    }
}

