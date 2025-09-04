//
// Created by Bland on 21/05/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "MapGenerator.h"

using namespace std;

//main - starting point for program
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // seed for random

    string name; //player name
    cout << "Enter your company name: ";
    getline(cin, name);

    Game game(name); //construct then run game
    game.run();

    return 0;
}
