#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include <ResourceManager/ResourceManager.hpp>
#include <Map/TileIsoHexa.hpp>

namespace cfg
{
    class Config
    {
        Config() = delete;
        Config(const Config&) = delete;
        Config& operator=(const Config&) = delete;

        public:

        static std::string tex_path;
        static std::string map_path;
        static sf::Font font;
        static rm::ResourceManager<std::string,sf::Texture> textureManager;
        static sf::Vector2i mapMoussPosition;
        static map::TileIsoHexa moussCursorTile;
        static sf::Texture moussCursorTex;
        static sf::Sprite moussCursorSpr;

        static void clear();
        static void drawCursor(sf::RenderWindow& target,sf::RenderStates states = sf::RenderStates::Default);
    };
};

#endif
