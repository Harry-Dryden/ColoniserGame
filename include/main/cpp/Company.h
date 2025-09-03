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
    int population;
    int workforce;
    int income;
    std::vector<Province*> ownedProvinces;

    public:
    Company(std::string nm);

    void displayStatus();

    std::string getName();

    std::vector<Province*> getOwnedProvinces();

    bool attemptColonise(Province& p);

    void updateIncome(int newIncome);

    void endTurnUpdate();
};

#endif //COMPANY_H