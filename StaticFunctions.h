#ifndef STATICFUNCTIONS_H
#define STATICFUNCTIONS_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class StaticFunctions
{
    public:
        StaticFunctions();
        virtual ~StaticFunctions();
        static std::vector<std::string> split(const std::string& s, char delimiter);

    protected:

    private:
};

#endif // STATICFUNCTIONS_H
