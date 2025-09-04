#include "Goods.h"

namespace Goods{
    std::vector<Good> goods = { //Vector of Goods
        Good("None",0,0), //ID =0 (Keep this way for province constructor)
        Good("Grain",1,40), //ID =1
        Good("Fish",1,30), //ID =2
        Good("Livestock",1,30), //ID =3
        Good("Spices",7,10),//ID =4
        Good("Iron",3,20), //ID =5
        Good("Gold",4,10),//ID =6
        Good("Gems",8,5),//ID =7
        Good("Wood",1,30), //ID =8
    };
}