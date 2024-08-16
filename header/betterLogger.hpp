#pragma once

// #file: betterLogger.hpp, header file
// #info: defines outline for project namespaces and class declorations
// #includes: includes.hpp, project includes

// project wide includes
#include "includes.hpp"

// #namespace: worTech(wt), developer namespace
// #info: holds all projects of worTech group
// #scope: global space
inline namespace worTech{
    // #namespace: betterLogger(better)(btr), project namespace
    // #info: holds all comonents of betterLogger project
    // #scope: worTech, developer namespace
    namespace betterLogger{
        // #namespace: concepts, component namespace
        // #info: holds concepts for betterLogger project
        // #scope: betterLogger, project namespace
        inline namespace concepts{}
        // #namespace: helpers, component namespace
        // #info: holds helper classes
        // #scope: betterLogger, project namespace
        inline namespace helpers{
            class Helper; using Help = Helper;
        }
        // #namespace: logStacks, component namespace
        // #info: holds log stacks
        // #scope: betterLogger, project namespace
        inline namespace logStacks{
            class LogStack;
        }
        // #
        inline namespace formats{
            namespace ansiiColorCodes{} namespace ansii = ansiiColorCodes;
            enum class LogLevel: uint8_t; using Level = LogLevel;
            enum class FormatType: uint8_t; using Format = FormatType;
            namespace logFormatting{} namespace log = logFormatting;
        }
        // #namespace: loggers, component namespace
        // #info: holds loggers and related implementation tools
        // #scope: betterLogger, project namespace
        inline namespace loggers{
            namespace defaultFormats{} namespace deflt = defaultFormats;
            class Logger;
        }
        // #namespace: defaultLogStacks, component namespace
        //#info: holds built in log stacks
        // #scope: betterLogger, project namespace
        inline namespace defaultLogStacks{
            class AutoFlush;
            class TerminateFlush;
        }
        // #namespace: defaultLoggers, component namespace
        // #info: holds built in loggers and related tools
        // #scope: betterLogger, project namespace
        inline namespace defaultLoggers{
            namespace loggerValues{} namespace logger = loggerValues;
            class Main;
            class Debug;
        }
    } namespace better = betterLogger; namespace btr = betterLogger;
} namespace wt = worTech;