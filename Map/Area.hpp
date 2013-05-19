#ifndef MAP_AREA_HPP
#define MAP_AREA_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

/* regroupe the tile of a common zone */
/* T is a tile class */

#define MAP_AREA_SIZE 8//2 4 8 16 32 64 128
 
namespace map
{

    template<class T> class AreaManager;
    template<class T> class AreaLoader;

    template<class T>
    class Area
    {
        public:
            /* X,Y = map coords (to multiply with MAP_AREA_SIZE)*/
            explicit Area(const int& X, const int& Y);
            ~Area();
            
            Area(const Area&) = delete;
            Area& operator=(const Area&) = delete;

            /* X,Y = map coords*/
            inline T* operator()(const int& X,const int& Y){
                clock.restart();
                return tiles[Y][X];
            };

            void draw(sf::RenderTarget& target, sf::RenderStates states= sf::RenderStates::Default);

            static sf::Vector2i toLocal(const int& X,const int& Y);
            static sf::Vector2i toLocal(const sf::Vector2i& pos);

            static sf::Vector2i toGlobal(const int& X,const int& Y);


        private:
            friend class AreaManager<T>;
            friend class AreaLoader<T>;
            T* tiles[MAP_AREA_SIZE][MAP_AREA_SIZE];
            sf::Clock clock;

    };
};

#include "Area.tpl"
#endif
