#pragma once

// #file:

#include "includes.hpp"

// #namespace: worTech, developer namespace
inline namespace worTech{
    // #namespace: betterLogger, project namespace
    namespace betterLogger{
        // #namespace: constants, component namespace
        inline namespace constants{
            namespace ansiiColorCodes{} namespace ansii = ansiiColorCodes;
            namespace logConstants{
                enum class LogLevel: uint8_t; using Level = LogLevel;
            } namespace log = logConstants;
        }
        // #namespace: helpers, component namespace
        inline namespace helpers{
            class Helper; using Help = Helper;
        }
        // #namespace: loggers, component namespace
        inline namespace loggers{
            class LogStack;
            class Logger;
        }
        // #namespace: defaultLoggers, component namespace
        inline namespace defaultLoggers{
            class Main;
            class Debug;
        }
    } namespace better = betterLogger;
} namespace wt = worTech;