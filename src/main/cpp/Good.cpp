#include "Good.h"

Good::Good(std::string n, int v, int r)
    : name(n), value(v), rarity(r){}

std::string Good::getName(){return name;}

int Good::getValue(){return value;}