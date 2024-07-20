#pragma once

// #

#include "betterLogger/namespaces.hpp"

namespace worTech::betterLogger::helpers{

    // #
    class Helper{
    public:
        static time_t getCurrentTime();
        static std::source_location getCurrentLocation();
    };

}