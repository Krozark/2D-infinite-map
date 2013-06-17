#ifndef MAP_AREASENDER_HPP
#define MAP_AREASENDER_HPP

#include "Area.hpp"
#include <Socket/SocketSerialized.hpp>

namespace map
{

    class AreaSender
    {
        AreaSender() = delete;
        AreaSender(const AreaSender&)= delete;
        AreaSender& operator=(const AreaSender&) = delete;

        public:
            static bool sendOnNetwork(const Area<T>& area);
            
            static ntw::SocketSerialized socket;
    };
}

#endif
