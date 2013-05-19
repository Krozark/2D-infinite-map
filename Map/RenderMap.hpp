#ifndef RENDERMAP_HPP
#define RENDERMAP_HPP

#include <SFML/Graphics.hpp>

#include "Map.hpp"

/* A class to display a map */
namespace map
{
    template<class T>
    class RenderMap : public sf::RenderTexture
    {
        public:
            explicit RenderMap(const int& X=0,const int Y=0);

            RenderMap(const RenderMap&) = delete;
            RenderMap& operator=(const RenderMap&) = delete;

        private:
            Map<T> _map;
    };
};

#endif
