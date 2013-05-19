#ifndef RENDERMAP_HPP
#define RENDERMAP_HPP

#include <SFML/Graphics.hpp>

#include "Map.hpp"

/* A class to display a map */
namespace map
{
    template<class T>
    class RenderMap : private sf::RenderTexture
    {
        public:
            /* RenderTexture.create args
             * unsigned int width, unsigned int height, bool depthBuffer=false
             * initial position 
             * X,Y
             */
            explicit RenderMap(unsigned int width, unsigned int height, bool depthBuffer=false,const int& X=0,const int Y=0);

            RenderMap(const RenderMap&) = delete;
            RenderMap& operator=(const RenderMap&) = delete;

            // in global coords
            /*void move(float offsetX, float offsetY);
            void move(const sf::Vector2f &offset);*/

            void draw(sf::RenderTarget &target,sf::RenderStates states=sf::RenderStates::Default);

        private:
            Map<T> _map;
            sf::Sprite sprite;

            void create(unsigned int width, unsigned int height, bool depthBuffer=false);
    };
};

#include "RenderMap.tpl"
#endif
