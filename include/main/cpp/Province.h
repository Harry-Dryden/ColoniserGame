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
    private:
    std::string name;
    bool colonised; //is the province already taken?
    Company* owner; //the Company which controls the province
    Good* tradeGood; //the Goods of the province
    int strength; //dictates difficulty to take or colonise
    int population; //the population of the province
    int economicVal; //potential economic value (redevlop to be based on trade good and population)
    int income; //realised economic income, based on potential economic value, trade good and population

    public:
    Province(std::string nm, int stren, int val); //province constructor

    void coloniseProvince(Company* coloniser); //essentially a second constructor for when a province is colonised

    void displayInfo();

    std::string getName();

    Company* getOwner();

    bool isColonised();

    int getStrength();

    void updatePopulation();

    void setPopulation(int pop);

    void updateIncome();
};

#endif //PROVINCE_H