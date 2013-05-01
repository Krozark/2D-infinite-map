#include "Tile.hpp"

#include <iostream>

namespace map
{
    Tile::Tile(const int& X, const int& Y) : x(X), y(Y)
    {
        std::cout<<this<<" Tile("<<X<<","<<Y<<");"<<std::endl;
    };

    Tile::~Tile()
    {};
};
