#pragma once

// #file:

#include "betterLogger.hpp"

#include "loggers.hpp"

namespace worTech::betterLogger::defaultLoggers{

    // #namespace: loggerValues(logger), variable namespace
    namespace loggerValues{
        const std::string MAIN_NAME = "main";
        const std::string DEBUG_NAME = "debug";
    }
    // #class: Main, singleton class
    class Main: public Logger{
    public:
        Main();
    };
    // #class: Debug, singleton class
    class Debug: public Logger{
    public:
        Debug();
    };

}