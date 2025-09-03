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
        displayMenu();
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                playerCompany->displayStatus();
                break;
            case 2:
                showColonisableProvinces();
                break;
            case 3:
                showAllProvinces();
                break;
            case 4:
                showMap();
                break;
            case 5:
                handleColonisation();
                break;
            case 6:
                cout<< "Ending turn...\n";
                turnUpdate();
                turn++;
                break;
            case 0:
                cout<< "Exiting game.";
                return;
            default:
                cout<<"Invalid input.\n";
        }
    }
}

void Game::displayMenu(){
    cout << "What would you like to do?\n";
    cout << "1. Show player status;\n";
    cout << "2. Show colonisable provinces;\n";
    cout << "3. Show all provinces;\n";
    cout << "4. Show the province map;\n";
    cout << "5. Attempt to colonise a new province;\n";
    cout << "6. End your turn;\n";
    cout << "0. Exit the game;\n";
    cout << "Choice: ";
}

void Game::showColonisableProvinces(){
    cout << "Colonisable provinces:\n";
    for (int provX = 0; provX < provinces.size(); ++provX){
        for (int provY = 0; provY < provinces[provX].size(); ++provY){
            if(provinces[provX][provY]->isColonisable()){
                cout << provX << " / " << provY << ". ";
                provinces[provX][provY]->displayInfo();
            }
        }
    }
}

void Game::showAllProvinces(){
    cout << "All provinces:\n";
    for (int provX = 0; provX < provinces.size(); ++provX){
        for (int provY = 0; provY < provinces[provX].size(); ++provY){
            cout << provX << " / " << provY << ". ";
            provinces[provY][provX]->displayInfo();
        }
    }
}

void Game::showMap(){
    for(int y=0; y<provinces.size(); ++y){
        for(int x=0; x<provinces[y].size(); ++x){
            Company* owner = provinces[y][x]->getOwner();
            if(owner!=nullptr){
                std::cout << owner->getName() <<" ";
            } else {
                Terrain provinceTerrain = provinces[y][x]->getTerrain();
                char symbol = terrainToSymbol(provinceTerrain);
                std::cout << symbol <<" ";
            }
        }
        std::cout << "\n" ;
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