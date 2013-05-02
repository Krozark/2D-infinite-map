#include <iostream>

#include "Map.hpp"

using namespace map;
using namespace std;

#include <math.h>

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
//#include <random>

//extern std::default_random_engine generator;

inline void rand_init() {
    srand(time(NULL));

};
inline float random(float min,float max) { return (rand()/float(RAND_MAX))*(max-min) + min; }
inline int random(int min,int max) { return rand()%(max-min+1) + min; }




#define PI 3.14159265

class Hexa
{
    public:
        Hexa(int X,int Y)
        {
            shape.setPointCount(6);
            float n = 100.0;
            float sin_60 = sin(60*PI/180)*n;

            shape.setPoint(0,sf::Vector2f(n/2,0));
            shape.setPoint(1,sf::Vector2f(3*n/2,0));
            shape.setPoint(2,sf::Vector2f(2*n,sin_60));
            shape.setPoint(3,sf::Vector2f(3*n/2,2*sin_60));
            shape.setPoint(4,sf::Vector2f(n/2,2*sin_60));
            shape.setPoint(5,sf::Vector2f(0,sin_60));

            shape.setOrigin(n,n);
            shape.setPosition(X,Y);

            shape.setFillColor(sf::Color(random(0,255),random(0,255),random(0,255)));

        }
        sf::ConvexShape shape;

};

float r_hauteur;
sf::Font font;

class Rotate_Hexa
{
    public:
        Rotate_Hexa(int X,int Y)
        {
            shape.setPointCount(6);
            float n = 50.0;
            float sin_75 = sin(75*PI/180)*n;
            float sin_15 = sin(15*PI/180)*n;
            float sin_45 = sin(45*PI/180)*n;

            shape.setPoint(0,sf::Vector2f(0,(sin_15+sin_75)/2));
            shape.setPoint(1,sf::Vector2f(sin_15,sin_15/2));
            shape.setPoint(2,sf::Vector2f(sin_15+sin_75,0));
            shape.setPoint(3,sf::Vector2f(sin_15+sin_75+sin_45,sin_45/2));
            shape.setPoint(4,sf::Vector2f(sin_75+sin_45,(sin_75+sin_45)/2));
            shape.setPoint(5,sf::Vector2f(sin_45,(sin_15+sin_75+sin_45)/2));
            
            r_hauteur = sin_15+sin_45+sin_75;
            shape.setOrigin(r_hauteur/2,r_hauteur/2);


            std::string text= std::to_string(X) + " " + std::to_string(Y);
            txt.setFont(font);
            txt.setString(text);
            txt.setCharacterSize(20);
            txt.setColor(sf::Color::White);
            txt.setOrigin(30,40);
            shape.setFillColor(sf::Color(random(0,255),random(0,255),random(0,255)));

            float decalage_x = (sin_45-sin_15);
            float decalage_y = (sin_75+sin_45);
    
            shape.setPosition(300+Y*decalage_x+X*decalage_y,300+Y*decalage_y/2+X*decalage_x/2);
            txt.setPosition(shape.getPosition());

            //shape.setFillColor(sf::Color::White);

        }
        sf::ConvexShape shape;
        sf::Text txt;

};

int main(int argc,char* argv[])
{
    rand_init();
    font.loadFromFile("Map/Map/data/ka1.ttf");
    /*cout<<"MAP_AREA_SIZE: "<<MAP_AREA_SIZE<<endl;
    Map<Tile> map_test;
    Tile* T = map_test(0,0);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(1,3);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(4,4);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(-1,-1);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;

    T= map_test(-12,42);
    cout<<"T:"<<T->x<<" "<<T->y<<endl;*/

    std::vector<Rotate_Hexa*> hexs;
    for(int x=-0;x<10;++x)
        for(int y=-0;y<10;++y)
            hexs.emplace_back(new Rotate_Hexa(x,y));

     // Create the main window
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "SFML window");
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
        for(auto hex: hexs)
        {
            window.draw(hex->shape);
            window.draw(hex->txt);
        }
        // Update the window
        window.display();
    }

    return 0;
};
