#include <Config.hpp>

std::string cfg::Config::tex_path("./data/textures/");
std::string cfg::Config::map_path("./data/map/");
sf::Font cfg::Config::font;
rm::ResourceManager<std::string,sf::Texture> cfg::Config::textureManager;
sf::Vector2i cfg::Config::mapMoussPosition;
map::TileIsoHexa cfg::Config::moussCursorTile(0,0);

namespace cfg
{
    void Config::clear()
    {
        textureManager.clear();
    };
};

