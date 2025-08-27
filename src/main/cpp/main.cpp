//
// Created by Bland on 21/05/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "MapGenerator.h"

using namespace std;

// Entry point
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // seed randomness

    auto Map = MapGenerator::generate(10,10);
    MapGenerator::printMap(Map);

    string name;
    cout << "Enter your company name: ";
    getline(cin, name);

    Game game(name);
    game.run();

    return 0;
}
