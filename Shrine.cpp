#include "Shrine.h"

Shrine::Shrine()
{
    //ctor
}

Shrine::~Shrine()
{
    //dtor
}

void Shrine::initShrine(Player &player){
    int randChoice1=0;
    int randChoice2=0;
    int randChoice3=0;
    int playerChoice;

    randChoice1 = rand()%9+1;
    do{
        randChoice2 = rand()%9+1;
    }while(randChoice2 == randChoice1);
    do{
        randChoice3 = rand()%9+1;
    }while(randChoice3 == randChoice1 || randChoice3 == randChoice2);

    //std::cout << randChoice1 << ":" << randChoice2 << ":" << randChoice3;
    _choix1 = readShrineFile(randChoice1);
    _choix2 = readShrineFile(randChoice2);
    _choix3 = readShrineFile(randChoice3);

    std::cout << "You found yourself in front of three altars. Choose wisely." << std::endl;
    std::cout << "1. " << _choix1[0] << " : " << _choix1[1] << std::endl;
    std::cout << "2. " << _choix2[0] << " : " << _choix2[1] << std::endl;
    std::cout << "3. " << _choix3[0] << " : " << _choix3[1] << std::endl;

    std::cin >> playerChoice;
    if(playerChoice == 1){
        choiceShrine(player, _choix1);
    }else if(playerChoice == 2){
        choiceShrine(player, _choix2);
    }else{
        choiceShrine(player, _choix3);
    }
}

std::vector<std::string> Shrine::readShrineFile(int idShrine){
    std::ifstream inFile;
    inFile.open("Shrine_file.txt");

    if (!inFile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }else{
        std::string line;

        inFile.seekg(std::ios::beg);
        for(int i=0; i < idShrine - 1; ++i){
        //    inFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            inFile.ignore(1000,'\n');
        }
        std::getline(inFile, line);

        std::vector<std::string> readShrine = StaticFunctions::split(line, ':');
        inFile.close();
        return readShrine;
    }
}

void Shrine::choiceShrine(Player &player, std::vector<std::string> chosenShrine){
    std::cout << chosenShrine[2] << std::endl;
    player.modifLifeMax(std::stoi(chosenShrine[3]));
    player.modifManaMax(std::stoi(chosenShrine[4]));
    player.modifAtk(std::stoi(chosenShrine[5]));
    player.modifDef(std::stoi(chosenShrine[6]));
    player.modifStress(std::stoi(chosenShrine[7]));
    player.modifLifeActual(std::stoi(chosenShrine[8]));
    player.modifDetection(std::stoi(chosenShrine[9]));
    player.modifGold(std::stoi(chosenShrine[10]));
    player.modifBluePrints(std::stoi(chosenShrine[11]));
}
