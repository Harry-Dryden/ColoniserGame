cmake_minimum_required(VERSION 3.29)
project(CGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include/main/cpp)

add_executable(CGame
    src/main/cpp/main.cpp
    src/main/cpp/Company.cpp
    src/main/cpp/Game.cpp
    src/main/cpp/Good.cpp
    src/main/cpp/Goods.cpp
    src/main/cpp/Population.cpp
    src/main/cpp/Province.cpp
    src/main/cpp/ProvinceLoader.cpp
    src/main/cpp/TerrainGoods.cpp
    )
