#include "TerrainGoods.h"
#include <unordered_map>

namespace TerrainGoods{
    const std::unordered_map<Terrain, std::vector<int>> terrainGoods = { //map of different terrains and a vector of the goods they can hold
        {Terrain::Coast, {1,2}}, //either grain or fish
        {Terrain::Island, {2,3}}, //either fish or livestock
        {Terrain::Grassland, {1,3,8}}, //either grain or livestock or wood (ADD WOODLAND TERRAIN LATER)
        {Terrain::Desert, {3,4}}, //either livestock or spices
        {Terrain::Hills, {3,5}}, //either livestock or iron
        {Terrain::Mountains, {5,6,7}}, //either iron or gold or gems (MAKE HARD TO COLONISE)
    };

    const std::vector<int> getPotentialGoods(Terrain terrain){ //getter for the potential goods of a terrain
        auto search = terrainGoods.find(terrain);
        if (search == terrainGoods.end()){
            return{}; //terrain not found
        }
        return search->second; //return the vector of potential goods (vector of ints for each good's id)
    }
}