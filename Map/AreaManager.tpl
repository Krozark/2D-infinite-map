namespace map
{
    template<class T>
    AreaManager<T>::AreaManager()
    {};

    template<class T>
    AreaManager<T>::~AreaManager(){};

    template<class T>
    void AreaManager<T>::add(Area<T>* area)
    {
        mutex.lock();
        areas.emplace_back(area);
        mutex.unlock();
    };

    template<class T>
    void AreaManager<T>::remove(Area<T>* area)
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
    void AreaManager<T>::start(const float time)
    {
        timeout = sf::seconds(time);
        void (AreaManager<T>::*f)(void) = &AreaManager<T>::run;
        thread = std::thread(f,this);
    }

    template<class T>
    void AreaManager<T>::run()
    {
        while(running)
        {
            mutex.lock();
            auto end = areas.end();
            for(auto i=areas.begin();i != end;++i)
            {
                Area<T>& current = *(*i);
                
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
