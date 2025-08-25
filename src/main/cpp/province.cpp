#include "Province.h"
#include "Company.h"
#include <iostream>
#include "Goods.h"

using namespace std;

Province::Province(string nm, int stren, int val)
    : name(nm), colonised(false), strength(stren), economicVal(val), owner(nullptr), 
    tradeGood(&Goods::goods.at(0)), population(0), income(0){}

void Province::coloniseProvince(Company* coloniser){
    population = 100;
    tradeGood = (&Goods::goods.at(1)); //initial test, sets good to grain for all provinces -- needs to be randomised later on
    owner = coloniser;
    colonised = true;
}

void Province::displayInfo(){ //displays basic information about the province, which changes when it is colonised
    cout << "Province: "<<name;
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

int Province::getStrength(){ //getter for province's strength (returns int)
    return strength;
}

int Province::getIncome(){ //getter for province's income(returns int)
    return income;
}

void Province::updatePopulation(){ //if province is owned, this updates the population within it
    population+=(population*0.2); //rate of 2% growth - obviously needs to be tested, and eventually each province wants a population cap
}

void Province::setPopulation(int pop){ //sets the new population of the province - probably only for use when province is colonised, rest should be dynamic
    population = pop;
}

void Province::updateIncome(){ //updates the economic value of the province
    int goodVal = tradeGood->getValue();
    income=(economicVal+goodVal)*population;
}