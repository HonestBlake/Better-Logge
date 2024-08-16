#pragma once 

// #

#include "betterLogger.hpp"

#include "formats.hpp"

namespace worTech::betterLogger::concepts{

    template<typename Type> concept StringType = std::is_same<std::decay_t<Type>, std::string>::value || std::is_same<std::decay_t<Type>, 
        const char*>::value;


}