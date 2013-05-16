//#include <iostream>

#include "TileIsoHexa.hpp"
//#include "AreaLoader.hpp"

namespace map
{
    template<class T>
        Map<T>::Map() : _last_area(0), areaManager(*this)
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
            sf::Vector2i area_pos(Area<T>::toLocal(X,Y));
            /* coor in the area */
            const int areaX = X & (MAP_AREA_SIZE -1);//< MAP_AREA_SIZE is 2^n so we can de this hack
            const int areaY = Y & (MAP_AREA_SIZE -1);

            return getOrCreateArea(area_pos.x,area_pos.y)(areaX,areaY);
        };

        /* For grid with fucking coords (hexa iso)*/
        template<>
        void Map<TileIsoHexa>::draw(sf::RenderTarget& target, sf::RenderStates states)
        {
            sf::Vector2u target_size = target.getSize();

            sf::Vector2f __right = target.mapPixelToCoords(sf::Vector2i(target_size.x+1,0));
            sf::Vector2f __left = target.mapPixelToCoords(sf::Vector2i(0,target_size.y+1));

            sf::Vector2i right(Area<TileIsoHexa>::toLocal(toLocal(__right.x,__right.y)));
            sf::Vector2i left(Area<TileIsoHexa>::toLocal(toLocal(__left.x,__left.y)));
            
            right = Area<TileIsoHexa>::toGlobal(right.x+1,right.y);
            left = Area<TileIsoHexa>::toGlobal(left.x,left.y+1);
            
            for(int y=right.y;y<=left.y;++y)
                for(int x=left.x;x<=right.x;++x)
                    (*this)(x,y)->draw(target,states);
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


            for(int y=top.y;y<=bottom.y;++y)
                for(int x=top.x;x<=bottom.x;++x)
                    (*this)(x,y)->draw(target,states);
        };
        
        template<class T>
        void Map<T>::draw_areas(sf::RenderTarget& target, sf::RenderStates states)
        {
            mutex.lock();

            auto end = areas.end();
            for(auto begin = areas.begin();begin != end;++begin)
            {
                begin->second->draw(target,states);
            }

            mutex.unlock();
        };

        /*********** private **********************/

        template<class T>
        bool Map<T>::remove(Area<T>* area)
        {
            if(mutex.try_lock())
            {
                auto end = areas.end();
                for(auto begin = areas.begin();begin != end;++begin)
                {
                    Area<T>* current = begin->second;
                    if(current == area)
                    {
                        areas.erase(begin);
                        delete current;
                        break;
                    }
                }   
         
                mutex.unlock();
                return true;
            }
            return false;
        };


        template<class T>
        Area<T>& Map<T>::getOrCreateArea(const int& X,const int& Y)
        {
            mutex.lock();
            if(_last_area and _last_area_X == X and _last_area_Y == Y)
            {
                mutex.unlock();
                return (*_last_area);
            }

            auto key = std::make_pair(X,Y);

            _last_area_X = X;
            _last_area_Y = Y;

            _last_area = areas[key];

            if (not _last_area)
            {
                _last_area = new Area<T>(_last_area_X, _last_area_Y);
                //AreaLoader<T>::loadFromFile(*_last_area,_last_area_X,_last_area_Y);
                areas[key] = _last_area;
                areaManager.add(_last_area);
            }
            mutex.unlock();
            return (*_last_area);
        };

};
