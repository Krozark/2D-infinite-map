#ifndef MAP_TILEISOHEXA_HPP
#define MAP_TILEISOHEXA_HPP

#include <SFML/Graphics.hpp>


/* the minimum unit for a map (a cell) 2D Iso Hexagone */
namespace map
{
    class TileIsoHexa
    {
        public:
            TileIsoHexa(const int& X,const int& Y);
            ~TileIsoHexa(){};
            TileIsoHexa(const TileIsoHexa&) = delete;
            TileIsoHexa& operator=(const TileIsoHexa&) = delete;

            void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

            template < typename ...Args>
            inline void setFillColor(const Args& ... args) {shape.setFillColor(args...);};

            static sf::Vector2i toLocal(const int& X,const int& Y);
            static sf::Vector2i toLocal(const sf::Vector2i& pos);

            static sf::Font font;

             void setPositionShape(const int& X,const int& Y);
             void setTexture(const sf::Texture *texture,bool resetRect=false);

        protected:
            sf::ConvexShape shape;
            sf::Text txt;

        //sprite
    };
};
#endif
