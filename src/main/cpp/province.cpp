#include "Province.h"
#include "Company.h"
#include <iostream>
#include "Goods.h"

using namespace std;

Province::Province(string nm, int stren, int val, Terrain terr)
    : name(nm), colonised(false), colonisable(terr==Terrain::Coast), strength(stren), economicVal(val), terrain(terr),
    owner(nullptr), tradeGood(&Goods::goods.at(0)), population(0), income(0){}

Province::Province(string nm, int stren, int val, Terrain terr, int fixedGoodID)
    : name(nm), colonised(false), strength(stren), economicVal(val), terrain(terr),
    owner(nullptr), tradeGood(&Goods::goods.at(fixedGoodID)), population(0), income(0){}

void Province::coloniseProvince(Company* coloniser){
    population = 10;
        if(tradeGood == &Goods::goods.at(0)){
            auto potentialGoods = TerrainGoods::getPotentialGoods(terrain);
            if (!potentialGoods.empty()) {
                int randomIndex = rand() % potentialGoods.size();
                int goodId = potentialGoods[randomIndex];
                tradeGood = &Goods::goods.at(goodId);
            } else {
                std::cerr << "No potential goods for terrain in province "
                        << name << std::endl;
                tradeGood = &Goods::goods.at(0); // fallback "None"
            }
        }
        owner = coloniser;
        colonised = true;
        colonisable = false;
}

void Province::displayInfo(){ //displays basic information about the province, which changes when it is colonised
    cout << "Province: " << name
         << " | Terrain: " << terrainToString(terrain);
    if (colonised == false){
        cout << " | Strength: " << strength
             << " | Potential Value: " << economicVal
             << endl;
    }
    else{
        cout << " | Trade Good: " << tradeGood->getName()
             << " | Population : " << population
             << " | Province Income: " << income
             << " | Owner: " << (owner ? owner->getName() : "None")
             << endl;
    }
}

std::string Province::getName(){ //getter for province name (returns std::string)
    return name;
}

Company* Province::getOwner(){ //getter for province owner (returns Company*)
    return owner;
}

bool Province::isColonised(){ //getter for wether province is colonised (returns bool - true if it is owned)
    return colonised;
}

bool Province::isColonisable(){ //getter for wether province is colonisable (returns bool - true if it is colonisable)
    return colonisable;
}

void Province::setColonisable(bool canBeColonised){
    colonisable = canBeColonised;
}

int Province::getStrength(){ //getter for province's strength (returns int)
    return strength;
}

int Province::getIncome(){ //getter for province's income(returns int)
    return income;
}

int Province::getPopulation(){ //getter for province population (returns int)
    return population;
}

Terrain Province::getTerrain(){ //getter for province terrain (returns Terrain)
    return terrain;
}

void Province::updatePopulation(){ //if province is owned, this updates the population within it
    population+=(population*0.2); //rate of 2% growth - obviously needs to be tested, and eventually each province wants a population cap
}

void Province::setPopulation(int pop){ //sets the new population of the province - probably only for use when province is colonised, rest should be dynamic
    population = pop;
}

void Province::addPopulation(int pop){ //adds to the existing population of the province
    population += pop;
}

void Province::setTradeGood(Good* newGood){
    tradeGood = newGood;
}

void Province::updateIncome(){ //updates the economic value of the province
    int goodVal = tradeGood->getValue();
    income=(economicVal+goodVal)*population;
}