#include <iostream>


#include <math.h>

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Map.hpp"
#include "TileIsoHexa.hpp"

using namespace map;
using namespace std;

int main(int argc,char* argv[])
{
    TileIsoHexa::font.loadFromFile("data/ka1.ttf");
    
    Map<TileIsoHexa> carte;
    
    TileIsoHexa mouse_hex(-2,-2);
    mouse_hex.setFillColor(sf::Color(255,255,255,175));


     // Create the main window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML window");
    while (window.isOpen())
    {
         // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        //map cord mousse
        sf::Vector2i pos(carte.toLocal(sf::Mouse::getPosition(window)));

        carte(pos.x,pos.y);

        carte.draw_areas(window); 

        mouse_hex.setPositionShape(pos.x,pos.y);
        mouse_hex.draw(window);

        // Update the window
        window.display();
    }

    return 0;
};
