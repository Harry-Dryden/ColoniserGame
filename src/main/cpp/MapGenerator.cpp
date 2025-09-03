#include "MapGenerator.h"
#include "TerrainDeterminer.h"
#include <iostream>


std::vector<std::vector<std::unique_ptr<Province>>> MapGenerator::generate(int width, int height){
    std::vector<std::vector<std::unique_ptr<Province>>> grid(
    height);
    for(int y=0; y<height; ++y){
        grid[y].resize(width);
        for(int x=0; x<width; ++x){
            std::string provName = "Province_" + std::to_string(y) + "_" + std::to_string(x);
            Terrain prevTerrainX;
            Terrain prevTerrainY;
            Terrain newTerrain;
            if(x==0||y==0){newTerrain=Terrain::Sea;} else {
                if(x>0){prevTerrainX = grid[y][x-1]->getTerrain();
                } else {prevTerrainX = Terrain::Sea;}
                if(y>0){prevTerrainY = grid[y-1][x]->getTerrain();
                } else {prevTerrainY = Terrain::Sea;}
                TerrainKey previousTerrains{prevTerrainX, prevTerrainY};
                auto mapIterator = terrainRulesMap.find(previousTerrains);
                if( mapIterator != terrainRulesMap.end()) {
                    auto& terrainWeightVector = mapIterator->second;
                    int possibiltyRoll = (rand() % 100)+1;
                    int runningSum =0;
                    for (int possibleTerrains=0; possibleTerrains<terrainWeightVector.size(); possibleTerrains++){
                        std::pair<Terrain,int> currPair = terrainWeightVector[possibleTerrains];
                        runningSum+= currPair.second;
                        if(runningSum>=possibiltyRoll){
                            newTerrain = currPair.first;
                            break;
                        }
                    }
                } else { newTerrain = Terrain::Sea;} //default for errors
            }
            /** OLD 'RANDOM' TERRAIN GEN
            int r = rand() % 100;
            Terrain terrain;
            if (r<20) terrain = Terrain::Sea; //20%
            else if (r<25) terrain = Terrain::River; //5%
            else if (r<35) terrain = Terrain::Coast; //10%
            else if (r<40) terrain = Terrain::Island; //5%
            else if (r<70) terrain = Terrain::Grassland; //30%
            else if (r<75) terrain = Terrain::Desert; //5%
            else if (r<90) terrain = Terrain::Hills; //15%
            else if (r<100) terrain = Terrain::Mountains; //10%
            **/
            int strength = 80;
            int value = 1;
            grid[y][x] = std::make_unique<Province>(provName, strength, value, newTerrain);
        }
    }
    return grid;
}

/** OLD PRINT MAP - NOW MOVED TO GAME.cpp
void MapGenerator::printMap(const std::vector<std::vector<std::unique_ptr<Province>>>& grid){
    for(int y=0; y<grid.size(); ++y){
        for(int x=0; x<grid[y].size(); ++x){
            Terrain provinceTerrain = grid[y][x]->getTerrain();
            char symbol = terrainToSymbol(provinceTerrain);
            std::cout << symbol <<" ";
        }
        std::cout << "\n" ;
    }
}
*/

/** OLD PROCEDURAL GENERATION - only based on left terrain, NOW MOVED TO TERRAINDETERMINER.H
Terrain MapGenerator::decideTerrain(Terrain prevTerrain, int x, int y){
    if(x==0){
        return Terrain::Sea;
    }
    int r = rand() % 100;
    Terrain terrain;
    if(prevTerrain==Terrain::Sea){
        if(r<80) terrain = Terrain::Sea;
        else if(r<90) terrain = Terrain::Island;
        else if(r<100) terrain = Terrain::Coast;
    }
    else if(prevTerrain==Terrain::Island){
        if(r<50) terrain = Terrain::Island;
        else if(r<100) terrain = Terrain::Sea;
    }
    else if(prevTerrain==Terrain::Coast){
        if(r<90) terrain = Terrain::Grassland;
        else if(r<100) terrain = Terrain::Coast;
    }
    else if(prevTerrain==Terrain::Grassland){
        if(r<80) terrain = Terrain::Grassland;
        else if(r<90) terrain = Terrain::Hills;
        else if(r<95) terrain = Terrain::Desert;
        else if(r<100) terrain = Terrain::River;
    }
    else if(prevTerrain==Terrain::Hills){
        if(r<60) terrain = Terrain::Hills;
        else if(r<80) terrain = Terrain::Mountains;
        else if(r<100) terrain = Terrain::Grassland;
    }
    else if(prevTerrain==Terrain::Mountains){
        if (r<80) terrain = Terrain::Mountains;
        else if (r<100) terrain = Terrain::Hills;
    }
    else if(prevTerrain==Terrain::Desert){
        if (r<60) terrain = Terrain::Desert;
        else if (r<80) terrain = Terrain::Hills;
        else if (r<100) terrain = Terrain::Grassland;
    }
    else if(prevTerrain==Terrain::River){
        terrain = Terrain::Grassland;
    }
    return terrain;
}
*/