#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(string playerName){
    turn=1;
    provinces = std::move(MapGenerator::generate(60, 20));
    companies.push_back(std::make_unique<Company>(playerName));
    playerCompany = companies[0].get(); 
}

void Game::run(){
    cout<<"Welcome to Coloniser!\n";
    while(true){
        cout<< "=|=|=|=|= Turn:" << turn << " =|=|=|=|=\n";
        playerCompany->displayStatus();
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
                turnUpdate();
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
    for (int provX = 0; provX < provinces.size(); ++provX){
        for (int provY = 0; provY < provinces[provX].size(); ++provY){
            cout << provX << " / " << provY << ". ";
            provinces[provX][provY]->displayInfo();
        }
    }
}

void Game::handleColonisation(){
    cout << "Enter the x of the province to colonise: ";
    int x;
    cin >> x;
    if (x < 1 || x > provinces.size()){
        cout << "Invalid province selection.\n";
        return;
    }
    cout << "Enter the y of the province to colonise: ";
    int y;
    cin >> y;
    if (y < 1 || y > provinces[y].size()){
        cout << "Invalid province selection.\n";
        return;
    }
    playerCompany->attemptColonise(*provinces[x][y]);
}

void Game::turnUpdate(){
    for (auto& company : companies){
        company->endTurnUpdate();
    }
}