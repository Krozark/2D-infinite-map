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

            // move the view (in px)
            template<typename ... Args >
            void move(Args&& ... args);

            //in Tile position (T) 
            void setViewPosition(const int& x,const int& y);

            void draw(sf::RenderTarget &target,sf::RenderStates states=sf::RenderStates::Default);

            template<typename ... Args >
            void setOrigin(Args&& ... args);

            template<typename ... Args >
            void setPosition(Args&& ... args);

            template<typename ... Args >
            sf::Vector2f getPosition(Args&& ... args);

            template<typename ... Args >
            sf::Vector2i mapPixelToCoords(Args&& ... args);

            template<typename ... Args >
            static sf::Vector2i mapCoordsToPixel(Args&& ... args);

        private:
            Map<T> _map;
            sf::Sprite sprite;

            void create(unsigned int width, unsigned int height, bool depthBuffer=false);
    };
};

#include "RenderMap.tpl"
#endif
