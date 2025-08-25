//Created by Harry on 25/08/25

#include "ProvinceLoader.h"
#include "Goods.h"

std::vector<std::unique_ptr<Province>> ProvinceLoader::loadInitialProvinces(){
    std::vector<std::unique_ptr<Province>> provinces;
    provinces.push_back(std::make_unique<Province>("Green Cove", 10, 20, Terrain::Coast));
    provinces.push_back(std::make_unique<Province>("Woodland Coast", 20, 30, Terrain::Coast));
    provinces.push_back(std::make_unique<Province>("Jungle Coast", 70, 100, Terrain::Coast));
    provinces.push_back(std::make_unique<Province>("Shipbreaker Bay", 120, 80, Terrain::Coast));
    provinces.push_back(std::make_unique<Province>("Pirate Coast", 200, 500, Terrain::Coast));
    provinces.push_back(std::make_unique<Province>("Rocky Island", 50, 70, Terrain::Island));
    provinces.push_back(std::make_unique<Province>("Unbroken Isles", 200, 500, Terrain::Island));
    return provinces;
} 
