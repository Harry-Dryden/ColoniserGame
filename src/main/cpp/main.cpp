//
// Created by Bland on 21/05/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace std;

// Entry point
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed RNG

    string name;
    cout << "Enter your company name: ";
    getline(cin, name);

    Game game(name);
    game.run();

    return 0;
}
