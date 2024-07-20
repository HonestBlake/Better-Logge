#pragma once

#include "../include/loggers.hpp"

namespace worTech::betterLogger::loggers{

// --------------------------------
// #div: LogStack, singleton class
// --------------------------------

// #div: public static methods

    // #
    LogStack& LogStack::get(){
        static LogStack instance = LogStack();
        return instance;
    }

// #div: public methods

    // #
    LogStack& LogStack::pushLog(const std::string& p_log){
        m_logBuffer.push_back(p_log);
        return *this;
    }
    // #
    LogStack& LogStack::pushLog(std::string&& p_log){
        m_logBuffer.push_back(std::forward<std::string>(p_log));
        return *this;
    }

    LogStack& LogStack::flush(){
        for(auto& log: m_logBuffer){
            std::cout << log << std::endl;
        }
        m_logBuffer.clear();
        return *this;
    }

// -----------------------------
// #div: Logger, abstract class
// -----------------------------

// #div: public static methods

    // #
    template<typename T_derived> Logger& Logger::get(){
        static Logger instance = T_derived();
        return instance;
    }

// #div: public methods

    // #
    Logger& Logger::log(const std::string& p_message){
        LogStack::get().pushLog(formatLog(log::Level::NONE, p_message));
        return *this;
    }
    // #
    Logger& Logger::log(std::string&& p_message){
        LogStack::get().pushLog(formatLog(log::Level::NONE, std::forward<std::string>(p_message)));
        return *this;
    }
    // #
    Logger& Logger::log(const std::string& p_message, const std::source_location& p_location){
        LogStack::get().pushLog(formatLog(log::Level::NONE, p_message, p_location));
        return *this;
    }
    // #
    Logger& Logger::log(std::string&& p_message, const std::source_location& p_location){
        LogStack::get().pushLog(formatLog(log::Level::NONE, std::forward<std::string>(p_message), p_location));
        return *this;
    }
    // #
    Logger& Logger::log(const std::string& p_message, const time_t& p_time){
        LogStack::get().pushLog(formatLog(log::Level::NONE, p_message, p_time));
        return *this;
    }
    // #
    Logger& Logger::log(std::string&& p_message, const time_t& p_time){
        LogStack::get().pushLog(formatLog(log::Level::NONE, std::forward<std::string>(p_message), p_time));
        return *this;
    }
    // #
    Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time){
        LogStack::get().pushLog(formatLog(log::Level::NONE, p_message, p_location, p_time));
        return *this;
    }
    // #
    Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time){
        LogStack::get().pushLog(formatLog(log::Level::NONE, std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(const std::string& p_message){
        LogStack::get().pushLog(formatLog(t_logLevel, p_message));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(std::string&& p_message){
        LogStack::get().pushLog(formatLog(t_logLevel, std::forward<std::string>(p_message)));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(const std::string& p_message, const std::source_location& p_location){
        LogStack::get().pushLog(formatLog(t_logLevel, p_message, p_location));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(std::string&& p_message, const std::source_location& p_location){
        LogStack::get().pushLog(formatLog(t_logLevel, std::forward<std::string>(p_message), p_location));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(const std::string& p_message, const time_t& p_time){
        LogStack::get().pushLog(formatLog(t_logLevel, p_message, p_time));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(std::string&& p_message, const time_t& p_time){
        LogStack::get().pushLog(formatLog(t_logLevel, std::forward<std::string>(p_message), p_time));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, 
    const time_t& p_time){
        LogStack::get().pushLog(formatLog(t_logLevel, p_message, p_location, p_time));
        return *this;
    }
    // #
    template<log::Level t_logLevel> Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time){
        LogStack::get().pushLog(formatLog(t_logLevel, std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }

// #div: protected factory methods

    // #
    Logger::Logger(const std::string& p_name): m_name(p_name){}
    // #
    Logger::Logger(std::string&& p_name): m_name(std::forward<std::string>(p_name)){}

// #div: protected methods

    // #
    std::string Logger::formatLocation(const std::source_location& p_location){
        return p_location.file_name() + log::SPACE + log::LINE_BEGIN + log::SPACE + std::to_string(p_location.line()) + log::SPACE 
            + p_location.function_name();
    }
    // #
    std::string Logger::formatTime(const time_t& p_time){
        std::tm* time = std::localtime(&p_time);
        return log::TIME_BEGIN + std::to_string(time->tm_hour) + log::TIME_SPACE + ((time->tm_min < 10)? "0": "") + std::to_string(time->tm_min) 
            + log::TIME_SPACE + ((time->tm_sec < 10)? "0": "") + std::to_string(time->tm_sec) + log::TIME_END;
    }
    // #
    std::string Logger::getLogColor(log::Level p_logLevel){
        return log::LEVEL_COLOR.at(p_logLevel);
    }
    // #
    std::string Logger::getLogColorBold(log::Level p_logLevel){
        return log::LEVEL_COLOR_BOLD.at(p_logLevel);
    }
    // #
    std::string Logger::getLogLevelName(log::Level p_logLevel){
        return log::LEVEL_NAME.at(p_logLevel);
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, const std::string& p_message){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ((p_logLevel != log::Level::NONE)? 
            getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET + getLogColor(p_logLevel) + log::SPACE: "") 
            + p_message + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, const std::string& p_message, const std::source_location& p_location){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ((p_logLevel != log::Level::NONE)? 
            getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET + getLogColor(p_logLevel) + log::SPACE: "") 
            + p_message +  log::SPACE + formatLocation(p_location) + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, const std::string& p_message, const time_t& p_time){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + formatTime(p_time) + log::SPACE 
            + ((p_logLevel != log::Level::NONE)? getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET 
            + getLogColor(p_logLevel) + log::SPACE: "") + p_message + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, const std::string& p_message, const std::source_location& p_location, 
    const time_t& p_time){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + formatTime(p_time) + log::SPACE 
        + ((p_logLevel != log::Level::NONE)? getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET 
        + getLogColor(p_logLevel) + log::SPACE: "") + p_message + log::SPACE + formatLocation(p_location) + ansii::RESET;
    }

    // #
    std::string Logger::formatLog(log::Level p_logLevel, std::string&& p_message){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ((p_logLevel != log::Level::NONE)? 
            getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET + getLogColor(p_logLevel) + log::SPACE: "")
            + std::forward<std::string>(p_message) + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, std::string&& p_message, const std::source_location& p_location){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ((p_logLevel != log::Level::NONE)? 
            getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET + getLogColor(p_logLevel) + log::SPACE: "")
            + std::forward<std::string>(p_message) + log::SPACE + formatLocation(p_location) + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, std::string&& p_message, const time_t& p_time){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + formatTime(p_time) + log::SPACE 
        + ((p_logLevel != log::Level::NONE)? getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET 
        + getLogColor(p_logLevel) + log::SPACE: "") + std::forward<std::string>(p_message) + ansii::RESET;
    }
    // #
    std::string Logger::formatLog(log::Level p_logLevel, std::string&& p_message, const std::source_location& p_location, 
    const time_t& p_time){
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + formatTime(p_time) + log::SPACE 
        + ((p_logLevel != log::Level::NONE)? getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + ansii::RESET 
        + getLogColor(p_logLevel) + log::SPACE: "") + std::forward<std::string>(p_message) + log::SPACE + formatLocation(p_location) 
        + ansii::RESET;
    }

}