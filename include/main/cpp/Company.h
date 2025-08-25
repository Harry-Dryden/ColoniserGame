//
// Created by Bland on 20/8/2025.
//

#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include "Province.h"

class Company {
    private:
    std::string name;
    int money;
    int people;
    int income;
    std::vector<Province*> ownedProvinces;

    public:
    Company(std::string nm);

    void displayStatus();

    std::string getName();

    bool attemptColonise(Province& p);

    void updateIncome(int newIncome);
};

#endif //COMPANY_H