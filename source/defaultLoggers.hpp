#pragma once

#include "header/defaultLoggers.hpp"

namespace worTech::betterLogger::defaultLoggers{

// #div: Main, singleton class

    Main::Main(): Logger(std::move(logger::MAIN_NAME)){}

// #div: Debug, singleton class
    
    Debug::Debug(): Logger(std::move(logger::DEBUG_NAME)){}
    
}