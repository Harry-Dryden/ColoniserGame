#ifndef GOOD_H
#define GOOD_H

#include <string>

class Good{
    private:
    std::string name;
    int value;
    int rarity;

    public:
    Good(std::string n, int v, int r);
    std::string getName();
};

#endif