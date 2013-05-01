namespace map
{
    template<class T>
    Map<T>::Map() : _last_area(0) 
    {
    };

    template<class T>
    Map<T>::~Map()
    {
        /*auto end = areas.end();
        for(auto begin = areas.begin();begin!=end;++begin)
            if (begin->second)
                delete (begin->second);*/
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


        if(_last_area_X == area_x and _last_area_Y == area_y)
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
};
