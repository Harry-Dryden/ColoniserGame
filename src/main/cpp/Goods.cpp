#include "Goods.h"

namespace Goods{
    std::vector<Good> goods = {
        Good("None",0,0), //ID =0 (Keep this way for province constructor)
        Good("Grain",10,40), //ID =1
        Good("Fish",10,30), //ID =2
        Good("Iron",30,20), //ID =3
        Good("Spices",40,10),//ID =4
    };
}