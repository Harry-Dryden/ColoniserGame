//
// Created by Bland on 20/8/2025.
//

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Company.h"
#include "Province.h"

class Game {
    private:
    Company player;
    std::vector<Province> provinces;
    int turn;

    public:
    Game(std::string playerName);

    void run();

    void displayMenu();

    void showProvinces();

    void handleColonisation();
};



#endif //GAME_H
