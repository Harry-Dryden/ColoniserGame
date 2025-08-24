#include "Province.h"
#include "Company.h"
#include <iostream>
#include "Goods.h"

using namespace std;

Province::Province(string nm, int stren, int val)
    : name(nm), colonised(false), strength(stren), economicVal(val), owner(nullptr), 
    tradeGood(&Goods::goods.at(0)){}

void Province::displayInfo(){
    cout << "Province: "<<name
         << " | Strength: " << strength
         << " | Value: " << economicVal
         << " | Colonised: " << (colonised ? "Yes" : "No")
         << " | Owner: " << (owner ? owner->name : "None")
         << " | Trade Good: " << tradeGood->getName()
         << endl;
}