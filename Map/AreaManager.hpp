#ifndef AREAMANAGER_HPP
#define AREAMANAGER_HPP

#include <thread>
#include <mutex>
#include <vector>

#include "Area.hpp"


/* Manage Areas and delete them after a none use time */

namespace map
{
    template<class T> class Map;

    template <class T>
    class AreaManager
    {
        public:
            explicit AreaManager(Map<T>& lmap);
            ~AreaManager();

            AreaManager(const AreaManager&) = delete;
            AreaManager& operator=(const AreaManager&) = delete;

            void add(Area<T>* area);

            void start(const float time=120);
            inline void stop(){running=false;};

            inline void setTimeout(const float time){this->timeout=time;};

        private:
            Map<T>& linkedMap;
            std::vector<Area<T>*> areas;
            std::mutex mutex;
            std::thread thread;
            sf::Time timeout;
            volatile bool running;

            void run();

            //void remove(Area<T>* area);
    };

};

#include "AreaManager.tpl"

#endif
