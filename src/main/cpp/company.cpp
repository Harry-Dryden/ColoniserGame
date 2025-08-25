#include "Company.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Company::Company(string nm)
    : name(nm), money(100), people(100), income(0) {}

void Company::displayStatus() {
    cout<<"Company: " << name
    << "| Money: " << money
    << "| People: " << people
    << "| Income: " << income << endl;
}

std::string Company::getName(){
    return name;
}

void Company::attemptColonise(Province& p){
    cout << "Attempting to colonise " << p.getName() << "...\n";
    if (p.isColonised()) {
        cout << "Province is already owned by " << (p.getOwner()->getName()) <<"!\n";
        return;
    }
    int pStrength = p.getStrength();
    int investment = 10 + pStrength;
    int manpowerCost = pStrength/2;

    if (money<investment || people < manpowerCost){
        cout << "Inadequate funds or men!\n";
        return;
    }

    cout << "Successful colonisation!\n";
    p.coloniseProvince(this);
    p.updateIncome();
    money -= investment;
    people -= manpowerCost;
    ownedProvinces.push_back(&p);
}

void Company::updateIncome(int newIncome){
}

void Company::endTurnUpdate(){
    income =0;
    people =0;
    for(Province* province : ownedProvinces){
        province->updatePopulation();
        province->updateIncome();
        income += province->getIncome();
        people += province->getPopulation();
    }
    money += income;
}