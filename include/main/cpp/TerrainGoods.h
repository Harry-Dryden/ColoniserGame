// Goods.h
#ifndef TERRAINGOODS_H
#define TERRAINGOODS_H

#include <vector>
#include "Goods.h"
#include "Terrain.h"

namespace TerrainGoods {
    const std::vector<int> getPotentialGoods(Terrain terrain);
}
#endif
