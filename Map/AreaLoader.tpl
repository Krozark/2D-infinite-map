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

        std::ifstream file(filename,std::ifstream::in);
        std::string line;

        std::cout<<filename<<std::endl;
        while(std::getline(file,line))
        {
            std::cout<<line<<std::endl;
        }
        file.close();
    };
        

    
    
};
