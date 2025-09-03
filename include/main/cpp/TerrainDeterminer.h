#ifndef TERRAINDETERMINER_H
#define TERRAINDETERMINER_H

#include "Terrain.h"
#include <unordered_map>
#include <vector>

struct TerrainKey{
    Terrain left;
    Terrain above;

    bool operator==(const TerrainKey& otherTerrainKey) const {
        return (left == otherTerrainKey.left && above == otherTerrainKey.above) || 
        (left == otherTerrainKey.above && above == otherTerrainKey.left);
    }
};

struct TerrainKeyHash{
    size_t operator()(const TerrainKey& key) const {
        std::size_t intLeft = std::hash<int>{} (static_cast<int>(key.left));
        std::size_t intAbove = std::hash<int>{} (static_cast<int>(key.above));
        return intLeft ^ intAbove;
    }
};

std::unordered_map<TerrainKey, std::vector<std::pair<Terrain, int>>, TerrainKeyHash> const terrainRulesMap = {
    {TerrainKey{Terrain::Sea, Terrain::Sea}, {{Terrain::Sea, 88}, {Terrain::Island, 10}, {Terrain::Coast, 2} } },
    {TerrainKey{Terrain::Sea, Terrain::Coast}, {{Terrain::Coast, 85}, {Terrain::Sea, 15} } },
    {TerrainKey{Terrain::Sea, Terrain::Island}, {{Terrain::Sea, 85}, {Terrain::Island, 15} } },
    {TerrainKey{Terrain::Sea, Terrain::Grassland}, {{Terrain::Coast, 100} } },

    {TerrainKey{Terrain::Island, Terrain::Island}, {{Terrain::Sea, 70}, {Terrain::Island, 30} } },
    {TerrainKey{Terrain::Island, Terrain::Coast}, {{Terrain::Sea, 100} } },


    {TerrainKey{Terrain::Coast, Terrain::Coast}, {{Terrain::Coast, 20}, {Terrain::Grassland, 80} } },
    {TerrainKey{Terrain::Coast, Terrain::Grassland}, {{Terrain::Grassland, 100} } },
    {TerrainKey{Terrain::Coast, Terrain::Desert}, {{Terrain::Grassland, 100} } },
    {TerrainKey{Terrain::Coast, Terrain::Hills}, {{Terrain::Grassland, 100} } },

    {TerrainKey{Terrain::Grassland, Terrain::Grassland}, {{Terrain::Grassland, 90}, {Terrain::Hills, 7}, {Terrain::Desert, 3} } },
    {TerrainKey{Terrain::Grassland, Terrain::Hills}, {{Terrain::Grassland, 50}, {Terrain::Hills, 50} } },
    {TerrainKey{Terrain::Grassland, Terrain::Desert}, {{Terrain::Grassland, 30}, {Terrain::Desert, 70} } },
    {TerrainKey{Terrain::Grassland, Terrain::Mountains}, {{Terrain::Hills, 100} } },


    {TerrainKey{Terrain::Hills, Terrain::Hills}, {{Terrain::Grassland, 10}, {Terrain::Hills, 70}, {Terrain::Mountains, 20} } },
    {TerrainKey{Terrain::Hills, Terrain::Mountains}, {{Terrain::Hills, 60}, {Terrain::Mountains, 40} } },
    {TerrainKey{Terrain::Hills, Terrain::Desert}, {{Terrain::Hills, 50}, {Terrain::Desert, 50} } },

    {TerrainKey{Terrain::Mountains, Terrain::Mountains}, {{Terrain::Hills, 20}, {Terrain::Mountains, 80} } },
    {TerrainKey{Terrain::Mountains, Terrain::Desert}, {{Terrain::Hills, 100} } },

    {TerrainKey{Terrain::Desert, Terrain::Desert}, {{Terrain::Desert, 80}, {Terrain::Grassland, 20} } },
};
#endif