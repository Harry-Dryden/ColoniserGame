#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <vector>
#include <memory>
#include "Province.h"

class MapGenerator {
    public:
    static std::vector<std::vector<std::unique_ptr<Province>>> generate(int width, int height);

//    static void printMap(const std::vector<std::vector<std::unique_ptr<Province>>>& grid);

//    static Terrain decideTerrain(Terrain prevTerrain, int x, int y);
};

#endif