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

sf::Font font;

float n = 50.0;
float sin_75 = sin(75*PI/180)*n;
float sin_15 = sin(15*PI/180)*n;
float sin_45 = sin(45*PI/180)*n;
float r_hauteur = sin_15+sin_45+sin_75;

float decalage_x = (sin_45-sin_15);
float decalage_y = (sin_75+sin_45);

class Rotate_Hexa
{
    public:
        Rotate_Hexa(int X,int Y)
        {
            shape.setPointCount(6);

            shape.setPoint(0,sf::Vector2f(0,(sin_15+sin_75)/2));
            shape.setPoint(1,sf::Vector2f(sin_15,sin_15/2));
            shape.setPoint(2,sf::Vector2f(sin_15+sin_75,0));
            shape.setPoint(3,sf::Vector2f(sin_15+sin_75+sin_45,sin_45/2));
            shape.setPoint(4,sf::Vector2f(sin_75+sin_45,(sin_75+sin_45)/2));
            shape.setPoint(5,sf::Vector2f(sin_45,(sin_15+sin_75+sin_45)/2));


            shape.setOrigin(r_hauteur/2,r_hauteur/4);


            txt.setFont(font);
            txt.setCharacterSize(20);
            txt.setColor(sf::Color::White);

            shape.setFillColor(sf::Color::Red);
            shape.setOutlineColor(sf::Color::Yellow);
            shape.setOutlineThickness(2);

            setPosition(X,Y);
        };

        void setPosition(int X,int Y)
        {
            shape.setPosition(Y*decalage_x+X*decalage_y,Y*decalage_y/2+X*decalage_x/2);

            std::string text= std::to_string(X) + " " + std::to_string(Y);
            txt.setString(text);
            sf::FloatRect rec = txt.getLocalBounds();
            txt.setOrigin(rec.width/2,rec.height/2);

            txt.setPosition(shape.getPosition());
        };

        static sf::Vector2i globleToLocal(sf::Vector2i pos)
        {
            //posx = Y*decalage_x+X*decalage_y
            //posy = Y*decalage_y/2+X*decalage_x/2;
            //x = decalage_x
            //y = decalage_y
            //a = pos.x
            //b = pos.y
            //Y = -x⁻³y³X+x⁻³y²a-2x⁻²yb+x⁻¹a
            //X = x⁻²y²X-x⁻²ya+2x⁻¹b
            int a = pos.x + r_hauteur/2;
            int b = pos.y + r_hauteur/4;
            float x =(2*b*decalage_x - a*decalage_y)/(decalage_x*decalage_x - decalage_y*decalage_y);
            float y= (2*b-x*decalage_x)/decalage_y;

            x=(x<0)?x-1:x;
            y=(y<0)?y-1:y;

            std::cout<<x<<" "<<y<<std::endl;


            pos.x = x;
            pos.y = y;
            return pos;
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
    for(int x=-10;x<20;++x)
        for(int y=-10;y<20;++y)
            hexs.emplace_back(new Rotate_Hexa(x,y));

    Rotate_Hexa mouse_hex(-2,-2);
    mouse_hex.shape.setFillColor(sf::Color(255,255,255,175));


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
        sf::Vector2i pos(Rotate_Hexa::globleToLocal(sf::Mouse::getPosition(window)));
        mouse_hex.setPosition(pos.x,pos.y);
        window.draw(mouse_hex.shape);
        window.draw(mouse_hex.txt);
        // Update the window
        window.display();
    }

    return 0;
};
