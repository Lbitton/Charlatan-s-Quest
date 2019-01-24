#ifndef STATICEVENTS_H
#define STATICEVENTS_H
#include "Player.h"

class StaticEvents
{
    public:
        StaticEvents();
        virtual ~StaticEvents();
        static void stressPlusOneAtRandom(Player &p);

    protected:

    private:
};

#endif // STATICEVENTS_H
