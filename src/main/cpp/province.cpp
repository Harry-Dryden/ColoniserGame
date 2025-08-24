#include "Province.h"
#include "Company.h"
#include <iostream>

using namespace std;

Province::Province(string nm, int stren, int val)
    : name(nm), colonised(false), strength(stren), economicVal(val), owner(nullptr){}

void Province::displayInfo(){
    cout << "Province: "<<name
         << " | Strength: " << strength
         << " | Value: " << economicVal
         << " | Colonised: " << (colonised ? "Yes" : "No")
         << " | Owner: " << (owner ? owner->name : "None")
         << endl;
}