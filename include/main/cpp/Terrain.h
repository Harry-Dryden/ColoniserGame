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
        case Terrain::Sea:       return "Sea";
        case Terrain::River:     return "River";
        case Terrain::Coast:     return "Coast";
        case Terrain::Island:    return "Island";
        case Terrain::Grassland: return "Grassland";
        case Terrain::Desert:    return "Desert";
        case Terrain::Hills:     return "Hills";
        case Terrain::Mountains: return "Mountains";
        default:                 return "Unknown";
    }
}

inline char terrainToSymbol(Terrain terrain){
    char symbol;
    switch(terrain){
        case Terrain::Sea:          symbol = '~'; break;
        case Terrain::River:        symbol = '='; break;
        case Terrain::Coast:        symbol = '#'; break;
        case Terrain::Island:       symbol = 'o'; break;
        case Terrain::Grassland:    symbol = '"'; break;
        case Terrain::Desert:       symbol = '.'; break;
        case Terrain::Hills:        symbol = '^'; break;
        case Terrain::Mountains:    symbol = 'M'; break;
    }
    return symbol;
}

#endif