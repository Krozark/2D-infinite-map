#ifndef AREAMANAGER_HPP
#define AREAMANAGER_HPP

#include <thread>
#include <vector>

#include "Area.hpp"

/* Manage Areas and delete them after a none use time */

namespace map
{

    template <class T>
    class AreaManager
    {
        public:
            AreaManager();
            ~AreaManager();

            AreaManager(const AreaManager&) = delete;
            AreaManager& operator=(const AreaManager&) = delete;

            void add(Area<T*> area);
            void remove(Area<T*> area);

            void start(const float time=120);
            inline void stop(){running=false;};

            inline void setTimeout(const float time){this->timeout=time;};

        private:
            std::vector<Area<T>*> areas;
            std::mutex mutex;
            std::thread thread;
            const sf::Time timeout;
            volatile bool running;

            void run();
    };

};

#include "AreaManager.tpl"

#endif
