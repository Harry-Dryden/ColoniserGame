#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(string playerName) : player(playerName), turn(1){
    provinces.push_back(Province("Green Coast", 10, 20));
    provinces.push_back(Province("Jungle Coast", 70, 100));
    provinces.push_back(Province("Pirate Coast", 200, 500));
}

void Game::run(){
    cout<<"Welcome to Coloniser!\n";
    while(true){
        cout<< "=|=|=|=|= Turn:" << turn << "=|=|=|=|=\n";
        player.displayStatus();
        showProvinces();
        displayMenu();

        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                handleColonisation();
                break;
            case 2:
                cout<< "Ending turn...\n";
                turn++;
                break;
            case 3:
                cout<< "Exiting game.";
                return;
            default:
                cout<<"Invalid input.\n";
        }
    }
}

void Game::displayMenu(){
    cout << "What would you like to do?\n";
    cout << "1. Attempt to colonise a new province;\n";
    cout << "2. End your turn;\n";
    cout << "3. Exit the game;\n";
    cout << "Choice: ";
}

void Game::showProvinces(){
    cout << "All provinces:\n";
    for (int provNum = 0; provNum < provinces.size(); ++provNum){
        cout << provNum + 1 << ".";
        provinces[provNum].displayInfo();
    }
}

void Game::handleColonisation(){
    cout << "Enter the number of the province to colonise: ";
    int index;
    cin >> index;
    if (index < 1 || index > provinces.size()){
        cout << "Invalid province selection.\n";
        return;
    }
    player.attemptColonise(provinces[index-1]);
}