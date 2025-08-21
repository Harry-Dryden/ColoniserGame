//
// Created by Bland on 20/8/2025.
//

#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
#include "Company.h"

//represents a province on the game map
class Province {
    public:
    std::string name;
    bool colonised; //is the province already taken
    Company* owner; //develop into a company* pointer later
    int strength; //dictates difficulty to take or colonise
    int population;
    int economicVal; //potential economic value
    std::string goods;

    Province(std::string nm, int stren, int val); //province constructor

    void displayInfo();
};

#endif //PROVINCE_H