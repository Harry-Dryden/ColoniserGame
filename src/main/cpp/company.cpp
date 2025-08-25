#include "Company.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Company::Company(string nm)
    : name(nm), money(100), manpower(100), income(10) {}

void Company::displayStatus() {
    cout<<"Company: " << name
    << "| Money: " << money
    << "| Manpower: " << manpower
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

    if (money<investment || manpower < manpowerCost){
        cout << "Inadequate funds or men!\n";
        return;
    }

    cout << "Successful colonisation!\n";
    p.coloniseProvince(this);
    p.updateIncome();
    money -= investment;
    manpower -= manpowerCost;
}