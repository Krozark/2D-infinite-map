#ifndef MAP_AREA_HPP
#define MAP_AREA_HPP

#include "Tile.hpp"

/* regroupe the tile of a common zone */

#define MAP_AREA_SIZE 8//2 4 8 16 32 64 128
 
namespace map
{
    /* T is a tile class */
    template<class T>
    class Area
    {
        public:
            /* X,Y = map coords (to multiply with MAP_AREA_SIZE)*/
            Area(const int& X, const int& Y);
            ~Area();
            
            Area(const Area&) = delete;
            Area& operator=(const Area&) = delete;

            /* X,Y = map coords*/
            inline T* operator()(const int& X,const int& Y) const {
                clock.restart();
                return tiles[X][Y];
            };

            sf::Clock clock;

        private:
            T* tiles[MAP_AREA_SIZE][MAP_AREA_SIZE];

    };
};

#include "Area.tpl"
#endif
