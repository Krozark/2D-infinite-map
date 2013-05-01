#ifndef MAP_MAP_HPP
#define MAP_MAP_HPP

#include <unordered_map>
#include <utility>

#include "Area.hpp"
#include "Tile.hpp"
#include "std_hash.hpp"


/* Store all the map (Areas)
 * and allaow you to load/unload piece of the map on the fly +
 * get +/- index for the map minimum cell (Tile)
 */
namespace map
{
    /* T is a tile class */
    template<class T>
    class Map
    {
        public:
            explicit Map();
            ~Map();

            Map(const Map&)=delete;
            Map& operator=(const Map&) = delete;

            T* operator()(const int& X,const int& Y);

        private:
            std::unordered_map<std::pair<int,int>,Area<T>*> areas;

            /* To optimise operator(int X, int Y) acces */
            Area<T>* _last_area;
            int _last_area_X;
            int _last_area_Y;

    };
};

#include "Map.tpl"
#endif
