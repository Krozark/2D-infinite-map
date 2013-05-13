#include <iostream>

#include "TileIsoHexa.hpp"

namespace map
{
    template<class T>
        Map<T>::Map() : _last_area(0) 
    {
        areaManager.start(120);
    };

    template<class T>
        Map<T>::~Map()
        {
            auto end = areas.end();
            for(auto begin = areas.begin();begin!=end;++begin)
                if (begin->second)
                    delete (begin->second);
        };


    template<class T>
        T* Map<T>::operator()(const int& X,const int& Y)
        {
            /* area coord */
            const int area_x = (X<0)?((X-MAP_AREA_SIZE+1)/MAP_AREA_SIZE):(X/MAP_AREA_SIZE);
            const int area_y = (Y<0)?((Y-MAP_AREA_SIZE+1)/MAP_AREA_SIZE):(Y/MAP_AREA_SIZE);

            /* coor in the area */
            const int areaX = X & (MAP_AREA_SIZE -1);//< MAP_AREA_SIZE is 2^n so we can de this hack
            const int areaY = Y & (MAP_AREA_SIZE -1);


            if(_last_area and _last_area_X == area_x and _last_area_Y == area_y)
                return (*_last_area)(areaX,areaY);

            auto key = std::make_pair(area_x,area_y);

            _last_area_X = area_x;
            _last_area_Y = area_y;

            _last_area = areas[key];

            if (not _last_area)
            {
                _last_area = new Area<T>(_last_area_X, _last_area_Y);
                areas[key] = _last_area;
            }
            return (*_last_area)(areaX,areaY);
        };

        
        /* For grid with fucking coords (hexa iso)*/
        template<>
        void Map<TileIsoHexa>::draw(sf::RenderTarget& target, sf::RenderStates states)
        {
            sf::Vector2u target_size = target.getSize();

            sf::Vector2f __top = target.mapPixelToCoords(sf::Vector2i(0,0));
            sf::Vector2f __right = target.mapPixelToCoords(sf::Vector2i(target_size.x+1,0));
            sf::Vector2f __bottom = target.mapPixelToCoords(sf::Vector2i(target_size.x+1,target_size.y+1));
            sf::Vector2f __left = target.mapPixelToCoords(sf::Vector2i(0,target_size.y+1));

            sf::Vector2i top = toLocal(__top.x,__top.y);
            sf::Vector2i right = toLocal(__right.x,__right.y);
            sf::Vector2i bottom = toLocal(__bottom.x,__bottom.y);
            sf::Vector2i left = toLocal(__left.x,__left.y);


            const float nb_x = right.x - top.x;
            const float nb_y = left.y - top.y;

            const float dec_x = nb_x / (nb_y - bottom.y - top.y);
            const float dec_y = nb_y / (nb_x - bottom.x - top.x );

            float c_x = dec_x/2;
            int decalage_x = 0;
            for(int x=0;x<=nb_x;++x)
            {
                float c_y = dec_y/2;
                int decalage_y = 0;
                for(int y=0;y<=nb_y;++y)
                {
                    (*this)(x-decalage_y,y-decalage_x)->draw(target,states);

                    if((c_y +=1.f) >= dec_y)
                    {
                        decalage_y +=1;
                        c_y -= dec_y;
                    }
                }
                if((c_x+=1.f) >= dec_x)
                {
                    decalage_x +=1;
                    c_x -= dec_x;
                }
            }

        };

       
        /* for a not rotate gride, it's ok */ 
        template <class T>
        void Map<T>::draw(sf::RenderTarget& target, sf::RenderStates states)
        {
            sf::Vector2u target_size = target.getSize();

            sf::Vector2f __top = target.mapPixelToCoords(sf::Vector2i(0,0));
            sf::Vector2f __bottom = target.mapPixelToCoords(sf::Vector2i(target_size.x+1,target_size.y+1));

            sf::Vector2i top = toLocal(__top.x,__top.y);
            sf::Vector2i bottom = toLocal(__bottom.x,__bottom.y);


            for(int x=top.x;x<=bottom.x;++x)
            {
                for(int y=top.y;y<=bottom.y;++y)
                    (*this)(x,y)->draw(target,states);
            }
        };
        
        template<class T>
        void Map<T>::draw_areas(sf::RenderTarget& target, sf::RenderStates states)
        {
            auto end = areas.end();
            for(auto begin = areas.begin();begin != end;++begin)
            {
                begin->second->draw(target,states);
            }
        };

};
