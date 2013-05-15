#include <Config.hpp>
#include <regex>
#include <fstream>

#include <iostream>

namespace map
{

    /*template<class T>
    void AreaLoader<T>::loadFromNetwork(Area<T>& area,const int& X,const int& Y)
    {
    };*/

    template<class T>
    void AreaLoader<T>::loadFromFile(Area<T>& area,const int& X,const int& Y)
    {
        std::string filename(cfg::Config::map_path+std::to_string(X)+","+std::to_string(Y));

        //ignore comment
        std::ifstream file(filename,std::ifstream::in);
        std::string line;

        if(file.is_open()) 
        {
            while(std::getline(file,line))
            {
                //comment
                if(line[0] == '#')
                    continue;

                //get coords
                int x,y;
                std::stringstream ss(line);
                ss>>x>>y;

                if(x < 0 or x >= MAP_AREA_SIZE or y < 0 or y >= MAP_AREA_SIZE)
                {
                    std::cerr<<"Coords not correct, min=0, and max=("<<MAP_AREA_SIZE-1<<") on file <"<<filename<<"> on line: "<<line<<std::endl;
                    continue;
                }

                std::string type;

                while(std::getline(ss,type,':'))
                {
                    //get values
                    std::string value;
                    ss>>value;
                    //remove ' ' before type 
                    type.erase(0,1);
                    //add to area what is needed
                    if(type == "tex")
                    {
                        if(value[0] == '"' or value[0] == '\'')
                            value = value.substr(1,value.size()-2);

                        sf::Texture* tex = 0;
                        if(cfg::Config::textureManager.find(value))
                        {
                            tex = &cfg::Config::textureManager[value];
                        }
                        else
                        {
                            sf::Texture tmp;
                            if(not tmp.loadFromFile(cfg::Config::tex_path+value))
                            {
                                std::cerr<<"Failed lo load "<<value<<" on coords <"<<x<<","<<y<<"> replace with default.png in file"<<filename<<std::endl;
                                tmp.loadFromFile(cfg::Config::tex_path+"default.png");
                            }

                            tex = &cfg::Config::textureManager.add(value,tmp);
                        }
                        area.tiles[x][y]->setTexture(tex);
                    }
                    else if (type == "obj")
                    {
                        std::cerr<<"Objects not yet makes ("<<value<<") on file <"<<filename<<"> on line: "<<line<<std::endl;
                    }
                }

            }
            file.close();
        }
        else
        {
            sf::Texture* tex = 0;
            std::string value("default.png");
            if(cfg::Config::textureManager.find(value))
            {
                tex = &cfg::Config::textureManager[value];
            }
            else
            {
                sf::Texture tmp;
                tmp.loadFromFile(cfg::Config::tex_path+value);
                tex = &cfg::Config::textureManager.add(value,tmp);
            }
            //set default textures
            for(int x=0;x<MAP_AREA_SIZE;++x)
                for(int y=0;y<MAP_AREA_SIZE;++y)
                    area.tiles[x][y]->setTexture(tex);
        }
        area.clock.restart();
    };
        

    
    
};
