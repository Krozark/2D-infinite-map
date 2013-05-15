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

        public:
            //X,Y cooord of Area
            static void loadFromNetwork(Area<T>& area,const int& X,const int& Y);
            //X,Y cooord of Area
            static void loadFromFile(Area<T>& area,const int& X,const int& Y);
    };
};


#include "AreaLoader.tpl"

#endif
