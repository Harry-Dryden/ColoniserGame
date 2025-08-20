#include "Company.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Company::Company(string nm)
    : name(nm), money(100), manpower(100), income(10) {}

void Company::displayStatus() {
    cout<<"Company: " << name
    << "| Money: £" << money
    << "| Manpower: " << manpower
    << "| Income: " << income << endl;
}

void Company::attemptColonise(Province& p){
    cout << "Attempting to colonise " << p.name << "...\n";
    if (p.colonised) {
        cout << "Province is already owned by " << p.owner <<"!\n";
        return;
    }
    int investment = 10 + p.strength;
    int manpowerCost = (p.strength/2);

    if (money<investment || manpower < manpowerCost){
        cout << "Inadequate funds or men!\n";
        return;
    }

    cout << "Successful colonisation!\n";
    p.colonised = true;
    p.owner = name;
    money -= investment;
    manpower -= manpowerCost;
}