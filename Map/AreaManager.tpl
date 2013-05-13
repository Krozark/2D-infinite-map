#include <iostream>

namespace map
{
    template<class T>
    AreaManager<T>::AreaManager(Map<T>& lmap) : linkedMap(lmap)
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

    /*template<class T>
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
    };*/

    template<class T>
    void AreaManager<T>::start(const float time)
    {
        timeout = sf::seconds(time);
        running = true;
        void (AreaManager<T>::*f)(void) = &AreaManager<T>::run;
        thread = std::thread(f,this);
    }

    template<class T>
    void AreaManager<T>::run()
    {
        std::cout<<"run()"<<std::endl;
        while(running)
        {
            mutex.lock();
            auto end = areas.end();
            for(auto i=areas.begin();i != end;++i)
            {
                Area<T>* current = (*i);
                std::cout<<current<<" "<<current->clock.getElapsedTime().asSeconds()<<std::endl;
                
                if(current->clock.getElapsedTime()>=timeout)
                {
                    if(linkedMap.remove(current))
                    {
                        i = areas.erase(i);
                        --i;
                    }
                    //delete current on map;
                }

            }
            mutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout<<"end run()"<<std::endl;
    };
};
