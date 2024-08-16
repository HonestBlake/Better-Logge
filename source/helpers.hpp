#pragma once

// #

#include "header/helpers.hpp"

namespace worTech::betterLogger::helpers{

    // #
    time_t Helper::getCurrentTime(){
        return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    }

}