#include "StaticFunctions.h"

StaticFunctions::StaticFunctions()
{
    //ctor
}

StaticFunctions::~StaticFunctions()
{
    //dtor
}

std::vector<std::string> StaticFunctions::split(const std::string& s, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
  //  std::string line = "Wallcrawlers:true:10:5:0:0:0:0";
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

