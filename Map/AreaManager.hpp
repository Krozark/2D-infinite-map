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
            AreaManager(const float sec_timeout);
            ~AreaManager();

            AreaManager(const AreaManager&) = delete;
            AreaManager& operator=(const AreaManager&) = delete;

            void add(Area<T*> area);
            void remove(Area<T*> area);

            void run();
            inline void stop(){running=false;};

        private:
            std::vector<Area<T>*> areas;
            std::mutex mutex;
            std::thread thread;

            const sf::Time timeout;

            volatile bool running;
    };

};

#include "AreaManager.tpl"

#endif
