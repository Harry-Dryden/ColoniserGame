//
// Created by Bland on 20/8/2025.
//

#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
class Company;
class Good;

//represents a province on the game map
class Province {
    public:
    std::string name;
    bool colonised; //is the province already taken?
    Company* owner; //the Company which controls the province
    Good* tradeGood; //the Goods of the province
    int strength; //dictates difficulty to take or colonise
    int population; //the population of the province
    int economicVal; //potential economic value (redevlop to be based on trade good and population)

    Province(std::string nm, int stren, int val); //province constructor

    void displayInfo();
};

#endif //PROVINCE_H