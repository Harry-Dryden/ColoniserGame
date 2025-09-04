#include "Good.h"

Good::Good(std::string n, int v, int r) //constructor for a good, with its string name, int value and int rarity
    : name(n), value(v), rarity(r){}

std::string Good::getName(){return name;} //getter for the Good's name

int Good::getValue(){return value;} //getter for the Good's value