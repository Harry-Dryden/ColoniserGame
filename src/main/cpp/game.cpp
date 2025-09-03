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
    for (int provY = 0; provY < provinces.size(); ++provY){
        for (int provX = 0; provX < provinces[provY].size(); ++provX){
            if(provinces[provY][provX]->isColonisable()){
                cout << provY << " / " << provX << ". ";
                provinces[provY][provX]->displayInfo();
            }
        }
    }
}

void Game::showAllProvinces(){
    cout << "All provinces:\n";
    for (int provY = 0; provY < provinces.size(); ++provY){
        for (int provX = 0; provX < provinces[provY].size(); ++provX){
            cout << provY << " / " << provX << ". ";
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
    cout << "Enter the y of the province to colonise: ";
    int y;
    cin >> y;
    if (y < 1 || y > provinces[y].size()){
        cout << "Invalid province selection.\n";
        return;
    }
    cout << "Enter the x of the province to colonise: ";
    int x;
    cin >> x;
    if (x < 1 || x > provinces.size()){
        cout << "Invalid province selection.\n";
        return;
    }
    if(provinces[y][x]->isColonisable()){ 
        playerCompany->attemptColonise(*provinces[y][x]);
        std::vector<std::pair<int,int>> directions = {
            {0, -1}, // north
            {0,  1}, // south
            {-1, 0}, // west
            {1,  0}  // east
        };
        for(int d = 0; d<directions.size(); d++){
            std::pair<int,int> currDirection = directions.at(d);
            int ny = currDirection.second + y;
            int nx = currDirection.first + x;
            if(ny>=0 && ny<provinces.size() && nx>=0 && nx<provinces[ny].size()){
                auto& neighbour = provinces[ny][nx];
                if(!neighbour->isColonised()){
                    if(neighbour->getTerrain()!=Terrain::Sea){
                        neighbour->setColonisable(true);
                        cout<< neighbour->getName() << " is colonisable!\n";
                    } else {
                        cout<< "Even our best sailors cannot colonise the sea. \n";
                    }
                } else {
                    cout<< "It appears this province has already been colonised! Perhaps we should ready our armies... \n";
                }
            } else {
                cout<< "The edge of the map has been reached! Perhaps it is a flat earth... \n";
            }
        }
    } else {
        cout<< "Despite our best efforts, this province isn't colonisable. \n";
    }
}

void Game::turnUpdate(){
    for (auto& company : companies){
        company->endTurnUpdate();
    }
}