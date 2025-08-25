#include "Goods.h"

namespace Goods{
    std::vector<Good> goods = {
        Good("None",0,0), //ID =0 (Keep this way for province constructor)
        Good("Grain",10,40), //ID =1
        Good("Fish",10,30), //ID =2
        Good("Livestock",10,30), //ID =3
        Good("Spices",70,10),//ID =4
        Good("Iron",30,20), //ID =5
        Good("Gold",40,10),//ID =6
        Good("Gems",80,5),//ID =7
        Good("Wood",10,30), //ID =8
    };
}