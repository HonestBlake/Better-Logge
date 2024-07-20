#pragma once

// #file:

#include "betterLogger/namespaces.hpp"

#include "loggers.hpp"

namespace worTech::betterLogger::defaultLoggers{
    
    // #class: Main, singleton class
    class Main: public better::Logger{
    public:
        Main(): Logger(log::MAIN_NAME){}
    };
    // #class: Debug, singleton class
    class Debug: public better::Logger{
    public:
        Debug(): Logger(log::DEBUG_NAME){}
    };

}