#ifndef MAP_TILE_HPP
#define MAP_TILE_HPP

#include <SFML/Graphics.hpp>

/* the minimum unit for a map (a cell) */
namespace map
{
    class Tile /*:  public sf::Drawable*/
    {
        public:
            Tile(const int& X,const int& Y);
            ~Tile();
            Tile(const Tile&) = delete;
            Tile& operator=(const Tile&) = delete;

            static sf::Vector2i toLocal(const int x,const int y);
            static sf::Vector2i toLocal(sf::Vector2i& v);

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states= sf::RenderStates::Default) const = 0;

        private:
            int x,y;
        //sprite
    };
};
#endif
