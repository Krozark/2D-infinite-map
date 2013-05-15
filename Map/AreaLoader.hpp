#ifndef AREALOADER_HPP
#define AREALOADER_HPP

/* Load tile of an area from file / socket ... */

namespace map
{
    template<class T>
    class AreaLoader
    {
        AreaLoader() = delete;
        ~AreaLoader() = delete;
        AreaLoader(const AreaLoader&) = delete;
        AreaLoader& operator=(const AreaLoader&) = delete;

        static void loadFromNetwork(Area& area,int X,int Y);//X.Y in MapCoord
        static void LoadFromFile(Area& area,int X,int Y);//X,Y in mapCoord
    };
};

#include "AreaLoader.tpl"

#endif
