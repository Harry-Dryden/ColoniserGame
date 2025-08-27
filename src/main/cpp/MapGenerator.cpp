#include "MapGenerator.h"
#include <iostream>


std::vector<std::vector<std::unique_ptr<Province>>> MapGenerator::generate(int width, int height){
    std::vector<std::vector<std::unique_ptr<Province>>> grid(
    height);
    for(int y=0; y<height; ++y){
        grid[y].resize(width);
        for(int x=0; x<width; ++x){
            std::string provName = "Province_" + std::to_string(x) + "_" + std::to_string(y);
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
            int strength = 10;
            int value = 10;
            grid[y][x] = std::make_unique<Province>(provName, strength, value, terrain);
        }
    }
    return grid;
}

void MapGenerator::printMap(const std::vector<std::vector<std::unique_ptr<Province>>>& grid){
    for(int y=0; y<grid.size(); ++y){
        for(int x=0; x<grid[y].size(); ++x){
            Terrain province = grid[y][x]->getTerrain();
            char symbol;
            switch(province){
                case Terrain::Sea:          symbol = '~'; break;
                case Terrain::River:        symbol = '='; break;
                case Terrain::Coast:        symbol = '#'; break;
                case Terrain::Island:       symbol = 'o'; break;
                case Terrain::Grassland:    symbol = '"'; break;
                case Terrain::Desert:       symbol = '.'; break;
                case Terrain::Hills:        symbol = '^'; break;
                case Terrain::Mountains:    symbol = 'M'; break;
            }
            std::cout << symbol <<" ";
        }
        std::cout << "\n" ;
    }
}
