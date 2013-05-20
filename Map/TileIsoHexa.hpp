#ifndef MAP_TILEISOHEXA_HPP
#define MAP_TILEISOHEXA_HPP

#include <SFML/Graphics.hpp>


/* the minimum unit for a map (a cell) 2D Iso Hexagone */
namespace map
{
    class TileIsoHexa
    {
        public:
            explicit TileIsoHexa(const int& X,const int& Y);
            ~TileIsoHexa(){};
            TileIsoHexa(const TileIsoHexa&) = delete;
            TileIsoHexa& operator=(const TileIsoHexa&) = delete;

            void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default,bool mouss=false) const;

            template < typename ...Args>
            inline void setFillColor(Args&& ... args) {shape.setFillColor(std::forward<Args&>(args)...);};

            static sf::Vector2i mapPixelToCoords(const int& X,const int& Y);
            static sf::Vector2i mapPixelToCoords(const sf::Vector2i& pos);

            static sf::Vector2f mapCoordsToPixel(const int& X,const int& Y);
            static sf::Vector2f mapCoordsToPixel(const sf::Vector2i& pos);


             void setPosition(const int& X,const int& Y);
             void setTexture(const sf::Texture *texture,bool resetRect=false);

             void setSprite(sf::Sprite*& spr);
             void setSprite(const sf::Texture& texture);

             void setSpriteOrigine(const float& X,const float&Y);

        protected:
            sf::ConvexShape shape;
            sf::Sprite* sprite;
            //sf::Text txt;

        //sprite
    };
};
#endif
