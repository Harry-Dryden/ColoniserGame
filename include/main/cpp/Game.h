//
// Created by Bland on 20/8/2025.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <memory>
#include "Company.h"
#include "Province.h"
#include "Terrain.h"
//#include "ProvinceLoader.h"
#include "MapGenerator.h"

class Game {
    private:
    std::vector<std::unique_ptr<Company>> companies;
    Company* playerCompany;
    std::vector<std::vector<std::unique_ptr<Province>>> provinces;
    int turn;

    public:
    Game(std::string playerName);

    void run();

    void displayMenu();

    void showColonisableProvinces();

    void showAllProvinces();

    void showOurProvinces();

    void showMap();

    void handleColonisation();

    void turnUpdate();
};



#endif //GAME_H
