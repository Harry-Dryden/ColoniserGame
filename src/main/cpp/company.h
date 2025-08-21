//
// Created by Bland on 20/8/2025.
//

#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include "Province.h"

class Company {
    public:
    std::string name;
    int money;
    int manpower;
    int income;

    Company(std::string nm);

    void displayStatus();

    void attemptColonise(Province& p, Company& c);
};

#endif //COMPANY_H