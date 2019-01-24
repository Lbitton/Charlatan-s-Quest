#ifndef SHRINE_H
#define SHRINE_H
#include <vector>
#include <iostream>
#include <fstream>
//#include <sstream>
#include "StaticFunctions.h"
#include "Player.h"

class Shrine
{
    public:
        Shrine();
        virtual ~Shrine();
        void initShrine(Player &player);
        std::vector<std::string> readShrineFile(int idShrine);
        void choiceShrine(Player &player, std::vector<std::string> chosenShrine);

    protected:

    private:
        std::vector<std::string> _choix1;
        std::vector<std::string> _choix2;
        std::vector<std::string> _choix3;
};

#endif // SHRINE_H
