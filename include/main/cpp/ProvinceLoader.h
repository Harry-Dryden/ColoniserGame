//Created by Harry on 25/08/25
//A clean space for loading provinces
//Hard coded (written in C++) at first - develop to load from .JSON later

#ifndef PROVINCELOADER_H
#define PROVINCELOADER_H

#include <vector>
#include <memory>
#include "Province.h"

class ProvinceLoader{
    public:
    static std::vector<std::unique_ptr<Province>> loadInitialProvinces();
};

#endif