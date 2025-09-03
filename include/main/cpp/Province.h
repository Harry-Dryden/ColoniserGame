//
// Created by Bland on 20/8/2025.
//

#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>
#include <vector>
#include "Terrain.h"
#include "TerrainGoods.h"
class Company;
class Good;

//represents a province on the game map
class Province {
    private:
    std::string name;
    bool colonised; //is the province already taken?
    bool colonisable; //is the province currently colonisable?
    Terrain terrain; //terrain from the enum
    Company* owner; //the Company which controls the province
    std::vector<Good*> potentialGoods;
    Good* tradeGood; //the Goods of the province
    int strength; //dictates difficulty to take or colonise
    int population; //the population of the province
    int economicVal; //potential economic value (redevlop to be based on trade good and population)
    int income; //realised economic income, based on potential economic value, trade good and population

    public:
    Province(std::string nm, int stren, int val, Terrain terr); //province 
    Province(std::string nm, int stren, int val, Terrain terr, int fixedGoodID); //province 

    void coloniseProvince(Company* coloniser); //essentially a second constructor for when a province is colonised

    void displayInfo();

    std::string getName();

    Company* getOwner();

    bool isColonised();

    bool isColonisable();

    void setColonisable(bool canBeColonised);

    int getStrength();

    int getIncome();

    int getPopulation();

    Terrain getTerrain();

    void updatePopulation();

    void setPopulation(int pop);

    void addPopulation(int pop);

    void setTradeGood(Good* newGood);

    void updateIncome();
};

#endif