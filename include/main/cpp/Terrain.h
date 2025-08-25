#ifndef TERRAIN_H
#define TERRAIN_H

enum class Terrain{ //terrain to be used
    Sea,
    River,
    Coast,
    Island,
    Grassland,
    Desert,
    Hills,
    Mountains
};

inline std::string terrainToString(Terrain terrain){
        switch (terrain) {
        case Terrain::Coast:    return "Coast";
        case Terrain::Island:   return "Island";
        case Terrain::Grassland:   return "Grassland";
        case Terrain::Desert:   return "Desert";
        case Terrain::Hills:    return "Hills";
        case Terrain::Mountains: return "Mountains";
        default:                return "Unknown";
    }
}

#endif