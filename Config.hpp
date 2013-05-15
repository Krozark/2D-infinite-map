#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include <ResourceManager/ResourceManager.hpp>

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
        static rm::ResourceManager<std::string,sf::Texture> textureManager;

        static void clear()
        {
            textureManager.clear();
        };
    };
};

std::string cfg::Config::tex_path("./data/textures/");
std::string cfg::Config::map_path("./data/map/");
rm::ResourceManager<std::string,sf::Texture> cfg::Config::textureManager;


#endif
