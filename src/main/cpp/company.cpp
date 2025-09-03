#include "Company.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Company::Company(string nm)
    : name(nm), money(100), workforce(100), income(0), population(40) {}

void Company::displayStatus() {
    cout<<"Company: " << name
    << "| Money: " << money
    << "| Population: " << population
    << "| Workforce: " << workforce
    << "| Income: " << income << endl;
}

std::string Company::getName(){
    return name;
}

std::vector<Province*> Company::getOwnedProvinces(){
    return ownedProvinces;
}

bool Company::attemptColonise(Province& p){
    cout << "Attempting to colonise " << p.getName() << "...\n";
    if (p.isColonised()) {
        cout << "Province is already owned by " << (p.getOwner()->getName()) <<"!\n";
        return false;
    }
    int pStrength = p.getStrength();
    int investment = 10 + pStrength;
    int manpowerCost = pStrength/2;

    if (money<investment || workforce < manpowerCost){
        cout << "Inadequate funds or men!\n";
        return false;
    }

    cout << "Successful colonisation!\n";
    p.coloniseProvince(this);
    p.updateIncome();
    money -= investment;
    workforce -=manpowerCost;
    cout << manpowerCost << " of our workforce has been lost in the colonisation effort.\n";
    cout << investment << " has been invested in the colonisation effort.\n";
    if (ownedProvinces.empty()) {
        p.addPopulation(population);
        cout << population << " people on our boats have arrived at our new colony.\n";
        population=0;
    }
    ownedProvinces.push_back(&p);
    return true;
}

void Company::updateIncome(int newIncome){
}

void Company::endTurnUpdate(){
    income =0;
    population =0;
    for(Province* province : ownedProvinces){
        province->updatePopulation();
        province->updateIncome();
        income += province->getIncome();
        population += province->getPopulation();
    }
    workforce += (population*0.2);
    money += income;
}