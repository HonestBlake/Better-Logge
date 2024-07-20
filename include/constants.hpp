#pragma once

// #

#include "betterLogger/namespaces.hpp"

namespace worTech::betterLogger::constants{
    // #
    namespace ansiiColorCodes{
        const std::string RESET = "\033[0m";
        const std::string BLACK = "\033[30m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\033[36m";
        const std::string WHITE = "\033[37m";
        const std::string BOLD_BLACK = "\033[1;30m";
        const std::string BOLD_RED = "\033[1;31m";
        const std::string BOLD_GREEN = "\033[1;32m";
        const std::string BOLD_YELLOW = "\033[1;33m";
        const std::string BOLD_BLUE = "\033[1;34m";
        const std::string BOLD_MAGENTA = "\033[1;35m";
        const std::string BOLD_CYAN = "\033[1;36m";
        const std::string BOLD_WHITE = "\033[1;37m";
    }
    // #
    namespace logConstants{
        // #
        enum class LogLevel: uint8_t{
            NONE,
            INFO,
            TRACE,
            WARN,
            ERR,
            CRIT
        };
        const std::string MAIN_NAME = "Main";
        const std::string DEBUG_NAME = "Debug";
        const std::string LOGGER_BEGIN = "[";
        const std::string LOGGER_END = "]";
        const std::string TIME_BEGIN = "(";
        const std::string TIME_END = ")";
        const std::string TIME_SPACE = ":";
        const std::string LEVEL_END = ":";
        const std::string LINE_BEGIN = "Line";
        const std::string SPACE = " ";
        // #
        const std::unordered_map<log::Level, std::string> LEVEL_NAME = {
            {Level::NONE, ""},
            {Level::INFO, "Info"},
            {Level::TRACE, "Trace"},
            {Level::WARN, "Warning"},
            {Level::ERR, "Error"},
            {Level::CRIT, "Critical"}
        };
        // #
        const std::unordered_map<log::Level, std::string> LEVEL_COLOR = {
            {Level::NONE, ansii::WHITE},
            {Level::INFO, ansii::CYAN},
            {Level::TRACE, ansii::GREEN},
            {Level::WARN, ansii::YELLOW},
            {Level::ERR, ansii::RED},
            {Level::CRIT, ansii::MAGENTA}
        };
        // #
        const std::unordered_map<log::Level, std::string> LEVEL_COLOR_BOLD = {
            {Level::NONE, ansii::BOLD_WHITE},
            {Level::INFO, ansii::BOLD_CYAN},
            {Level::TRACE, ansii::BOLD_GREEN},
            {Level::WARN, ansii::BOLD_YELLOW},
            {Level::ERR, ansii::BOLD_RED},
            {Level::CRIT, ansii::BOLD_MAGENTA}
        };
    }

}