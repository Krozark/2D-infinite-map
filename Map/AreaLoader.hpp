#ifndef AREALOADER_HPP
#define AREALOADER_HPP

#include "Area.hpp"

/* Load tile of an area from file / socket ... */

namespace map
{
    template<class T>
    class AreaLoader
    {
        AreaLoader() = delete;
        //~AreaLoader() = delete;
        AreaLoader(const AreaLoader&) = delete;
        AreaLoader& operator=(const AreaLoader&) = delete;

        static void loadFromNetwork(Area<T>& area,int X,int Y);//X.Y in MapCoord
        static void LoadFromFile(Area<T>& area,int X,int Y);//X,Y in mapCoord
    };
};


#include "AreaLoader.tpl"

#endif
