#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(string playerName){ //Game constructor, taking in the player's company's name as a string
    turn=1;
    provinces = std::move(MapGenerator::generate(60, 20)); //generate the 2D vector of provinces
    companies.push_back(std::make_unique<Company>(playerName)); //add the player's company to companies
    playerCompany = companies[0].get(); //set the player company as a special var for readability
}

void Game::run(){ //main game loop
    cout<<"Welcome to Coloniser!\n";
    while(true){
        cout<< "=|=|=|=|= Turn:" << turn << " =|=|=|=|=\n";
        playerCompany->displayStatus();
        displayMenu();
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            //FOR LOOP FOR OTHER COMPANIES
                playerCompany->displayStatus();
                break;
            case 2:
                showOurProvinces();
                break;
            case 3:
                showColonisableProvinces();
                break;
            case 4:
                showAllProvinces();
                break;
            case 5:
                showMap();
                break;
            case 6:
                handleColonisation();
                turnUpdate(); //colonising currently ends the turn - may change later
                break;
            case 7:
                turnUpdate();
                break;
            case 0:
                cout<< "Exiting game.";
                return;
            default:
                cout<<"Invalid input.\n";
        }
    }
}

void Game::displayMenu(){ //displays the game menu
    cout << "What would you like to do?\n";
    cout << "1. Show company statuses;\n";
    cout << "2. Show our provinces;\n";
    cout << "3. Show colonisable provinces;\n";
    cout << "4. Show all provinces;\n";
    cout << "5. Show the province map;\n";
    cout << "6. Attempt to colonise a new province;\n";
    cout << "7. End your turn;\n";
    cout << "0. Exit the game;\n";
    cout << "Choice: ";
}

void Game::showColonisableProvinces(){ //shows the provinces which are currently colonisable for the player
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

void Game::showAllProvinces(){ //shows all provinces (REALLY LONG LIST - NOT OVERLY USEFUL)
    cout << "All provinces:\n";
    for (int provY = 0; provY < provinces.size(); ++provY){
        for (int provX = 0; provX < provinces[provY].size(); ++provX){
            cout << provY << " / " << provX << ". ";
            provinces[provY][provX]->displayInfo();
        }
    }
}

void Game::showOurProvinces(){ //shows all of the player company's provinces
    cout << "Our provinces:\n";
    std::vector<Province*> ownedProvinces = playerCompany->getOwnedProvinces();
    for (int p=0; p<ownedProvinces.size(); p++){
        ownedProvinces[p]->displayInfo();
    }
}

void Game::showMap(){ //shows the game map using symbols for each terrain, and using a company's name where a company owns a province (should be a char instead of the whole string)
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

void Game::handleColonisation(){ //handles colonisation input
    cout << "Enter the y of the province to colonise: ";
    int y;
    cin >> y;
    if (y < 1 || y > provinces.size()){ //if province isnt in the list
        cout << "Invalid province selection.\n";
        return;
    }
    cout << "Enter the x of the province to colonise: ";
    int x;
    cin >> x;
    if (x < 1 || x > provinces[y].size()){ //if province isnt in the list
        cout << "Invalid province selection.\n";
        return;
    }
    if(provinces[y][x]->isColonisable()){  //if this province has the bool colonisable set to true
        if(playerCompany->attemptColonise(*provinces[y][x])){
            std::vector<std::pair<int,int>> directions = { //vector of pairs for each cardinal direction
                {0, -1}, // north
                {0,  1}, // south
                {-1, 0}, // west
                {1,  0}  // east
            };
            for(int d = 0; d<directions.size(); d++){ //for the directions
                std::pair<int,int> currDirection = directions.at(d); //the current direction being looked at
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
            cout<< "We are lacking in funds or people to colonise this province. \n";
        }
    }  else {
        cout<< "Despite our best efforts, this province isn't colonisable. \n";
    }
}

void Game::turnUpdate(){ //ends the game turn, updates all the companies
    cout<< "Ending turn...\n";
    turn++;
    for (auto& company : companies){
        company->endTurnUpdate();
    }
}