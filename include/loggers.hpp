#pragma once

// #file: logger.hpp, header file

#include "betterLogger/namespaces.hpp"

#include "constants.hpp"

namespace worTech::betterLogger::loggers{

    // #class: LogStack, singleton class
    class LogStack{
    public:
    // #div: public factory methods
        ~LogStack() = default; 
    // #div: public static methods
        static LogStack& get();
    // #div: public methods
        LogStack& pushLog(const std::string& p_log);
        LogStack& pushLog(std::string&& p_log);
        LogStack& flush();
    private:
    // #div: private factory methods
        LogStack() = default;
    // #div: private members
        std::vector<std::string> m_logBuffer;
    };
    // #class: Logger, abstract class 
    class Logger{
    public:
    // #div: public factory methods
        virtual ~Logger() = default;
    // #div: public static methods
        template<typename T_derived> static Logger& get();
    // #div: public methods
        Logger& log(const std::string& p_message);
        Logger& log(std::string&& p_message);
        Logger& log(const std::string& p_message, const std::source_location& p_location);
        Logger& log(std::string&& p_message, const std::source_location& p_location);
        Logger& log(const std::string& p_message, const time_t& p_time);
        Logger& log(std::string&& p_message, const time_t& p_time);
        Logger& log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time);
        Logger& log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time);
        template<log::Level t_logLevel> Logger& log(const std::string& p_message);
        template<log::Level t_logLevel> Logger& log(std::string&& p_message);
        template<log::Level t_logLevel> Logger& log(const std::string& p_message, const std::source_location& p_location);
        template<log::Level t_logLevel> Logger& log(std::string&& p_message, const std::source_location& p_location);
        template<log::Level t_logLevel> Logger& log(const std::string& p_message, const time_t& p_time);
        template<log::Level t_logLevel> Logger& log(std::string&& p_message, const time_t& p_time);
        template<log::Level t_logLevel> Logger& log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time);
        template<log::Level t_logLevel> Logger& log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time);
    protected:
    // #div: protected factory methods
        Logger(const std::string& p_name);
        Logger(std::string&& p_name);
    // #div: protected members
        const std::string m_name;
    // #div: protected methods
        virtual std::string formatLocation(const std::source_location& p_location);
        virtual std::string formatTime(const time_t& p_time);
        virtual std::string getLogColor(log::Level p_logLevel);
        virtual std::string getLogColorBold(log::Level p_logLevel);
        virtual std::string getLogLevelName(log::Level p_logLevel);
        virtual std::string formatLog(log::Level p_logLevel, const std::string& p_message);
        virtual std::string formatLog(log::Level p_logLevel, const std::string& p_message, const std::source_location& p_location);
        virtual std::string formatLog(log::Level p_logLevel, const std::string& p_message, const time_t& p_time);
        virtual std::string formatLog(log::Level p_logLevel, const std::string& p_message, const std::source_location& p_location, 
            const time_t& p_time);
        virtual std::string formatLog(log::Level p_logLevel, std::string&& p_message);
        virtual std::string formatLog(log::Level p_logLevel, std::string&& p_message, const std::source_location& p_location);
        virtual std::string formatLog(log::Level p_logLevel, std::string&& p_message, const time_t& p_time);
        virtual std::string formatLog(log::Level p_logLevel, std::string&& p_message, const std::source_location& p_location, 
            const time_t& p_time);
    };
    
}