#include "Company.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Company::Company(string nm) //constructor for the company, gives starting money, workforce and population, takes in a string for the company's name
    : name(nm), money(100), workforce(100), income(0), population(40) {}

void Company::displayStatus() { //displays the current status of the company
    cout<<"Company: " << name
    << "| Money: " << money
    << "| Population: " << population
    << "| Workforce: " << workforce
    << "| Income: " << income << endl;
}

std::string Company::getName(){ //getter for the company name (returns a string)
    return name;
}

std::vector<Province*> Company::getOwnedProvinces(){ //getter for the company's owned provinces (returns a vector of Province pointers)
    return ownedProvinces;
}

bool Company::attemptColonise(Province& p){ //attempts to colonise a specific province using company money and workforce
    cout << "Attempting to colonise " << p.getName() << "...\n";
    if (p.isColonised()) {
        cout << "Province is already owned by " << (p.getOwner()->getName()) <<"!\n";
        return false;
    }
    int pStrength = p.getStrength(); //get the strength of the province and work out the investment (money cost) and manpower cost (workforce cost) to colonise
    int investment = 10 + pStrength; //change the +10 and the /2 to int variables!!
    int manpowerCost = pStrength/2;

    if (money<investment || workforce < manpowerCost){ //if we dont have the workforce or the money
        cout << "Inadequate funds or men!\n";
        return false;
    }

    cout << "Successful colonisation!\n";
    p.coloniseProvince(this); //set the province to be colonised by this company
    money -= investment; //taking the invested money from our money
    workforce -=manpowerCost; //taking the manpower costfrom our workforce
    cout << manpowerCost << " of our workforce has been lost in the colonisation effort.\n";
    cout << investment << " of our gold has been invested in the colonisation effort.\n";
    if (ownedProvinces.empty()) { //if this is our first province
        p.addPopulation(population); //add our starting people to the province (provides a small boost to our start)
        cout << population << " people on our boats have arrived at our new colony.\n";
        population=0;
    }
    p.updateIncome(); //update the income of the province based off its new trade good and population
    ownedProvinces.push_back(&p); //add province to our owned provinces
    return true; //tell game.cpp this province was colonised successfully
}

void Company::updateIncome(int newIncome){
}

void Company::endTurnUpdate(){ //ends the turn for the company, going through its provinces to update their income and population and then updating its workforce and money
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