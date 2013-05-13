namespace map
{
    template<class T>
    AreaManager<T>::AreaManager()
    {};

    template<class T>
    AreaManager<T>::~AreaManager(){};

    template<class T>
    AreaManager<T>::add(Area<T*> area)
    {
        mutex.lock();
        areas.emplace_back(area);
        mutex.unlock();
    };

    template<class T>
    AreaManager<T>::remove(Area<T>* area)
    {
        mutex.lock();
        auto end = areas.end();
        for(auto i=areas.begin();i != end;++i)
            if((*i)==area)
            {
                areas.erase(i);
                break;
            }
        mutex.unlock();
    };

    template<class T>
    AreaManager<T>::start(const float time)
    {
        timeout = time;
        thread = std::thread(&AreaManager<T>::run,this);
    }

    template<class T>
    AreaManager<T>::run()
    {
        while(running)
        {
            mutex.lock();
            auto end = areas.end();
            for(auto i=areas.begin();i != end;++i)
            {
                Area<T>& current = (*i);
                
                if(current.clock.getElapsedTime()>=timeout)
                {
                    areas.erase(i);
                    //delete current on map;
                }

            }
            mutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        };
    };
};
