#include <vector>
#include <memory>
#include "Province.h"

class MapGenerator {
    public:
    static std::vector<std::vector<std::unique_ptr<Province>>> generate(int width, int height);

    static void printMap(const std::vector<std::vector<std::unique_ptr<Province>>>& grid);
};