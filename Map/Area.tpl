#include "AreaLoader.hpp"

namespace map
{
    /* coords to convert using MAP_AREA_SIZE */
    template<class T>
    Area<T>::Area(const int& X,const int& Y)
    {
        int x_min = X*MAP_AREA_SIZE;
        int y_min = Y*MAP_AREA_SIZE;


        for(int y=0;y<MAP_AREA_SIZE;++y)
            for(int x=0;x<MAP_AREA_SIZE;++x)
                tiles[y][x] = new T(x_min+x,y_min+y);

        AreaLoader<T>::loadFromFile(*this,X,Y);

    };
;
    template<class T>
    Area<T>::~Area()
    {
        /* delete all the datas */
        for(int i=0;i<MAP_AREA_SIZE;++i)
            for(int j=0;j<MAP_AREA_SIZE;++j)
                if(tiles[i][j])
                {
                    delete tiles[i][j];
                    tiles[i][j] = 0;
                }
    }

    template<class T>
    void Area<T>::draw(sf::RenderTarget& target, sf::RenderStates states)
    {
        for(int i=0;i<MAP_AREA_SIZE;++i)
            for(int j=0;j<MAP_AREA_SIZE;++j)
                tiles[i][j]->draw(target,states);
                
    };
};
