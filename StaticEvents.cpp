#include "StaticEvents.h"

StaticEvents::StaticEvents()
{
    //ctor
}

StaticEvents::~StaticEvents()
{
    //dtor
}

void StaticEvents::stressPlusOneAtRandom(Player &p){
    int randStress = rand()%12 + 1;
    if(randStress > 10){
        p.modifStress(1);
        std::cout << "THERE IS NO ESCAPING. THEY ARE EVERYWHERE ! Stress +1. "
            << p.getStress() << "/" << p.getStressMax() << "." << std::endl;
    }
}
