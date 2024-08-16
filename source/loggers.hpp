#pragma once

// #file: source/loggers.hpp, source file
// #info: holds function definitions for the Logger class
// #includes: header/loggers.hpp, project includes

// decloration header
#include "header/loggers.hpp"

namespace worTech::betterLogger::loggers{

// #div: public static methods

    // #func: get<T_derived>(), public static method
    // #info: holds a static instance of the derived logger class and returns that instance
    // #scope: Logger, abstract singleton class
    // #template: class T_derived, derived logger class type
    // #return: const Logger&, reference to the derived logger class instance
    template<class T_derived> Logger& Logger::get(){
        static T_derived instance = T_derived();
        return instance;
    }

// #div: public methods

    // #func: log<T_message>(T_message&&), const public generic method
    // #info: logs a message with no log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: StringType T_message, string type of message
    // #overload: 
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&)
    // #param: T_message&& p_message, message to log
    // #return: const Logger&, reference to current logger instance
    const Logger& Logger::log(const std::string& p_message)const{
        sendLog(formatLog<Level::NONE>(p_message, std::nullopt, std::nullopt));
        return *this; 
    }
    // #func: log<T_message, T_location>(T_message&&, T_location&&), const public generic method
    // #info: logs a message with no log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: StringType T_message, string type of message
    // #template: LocationType T_location, location type of source location
    // #overload: 
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, std::source_location&&)
    // #param: T_message&& p_message, message to log
    // #param: T_location&& p_location, source location of the message
    // #return: const Logger&, reference to current logger instance
    const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<Level::NONE>(p_message, p_location, std::nullopt));
        return *this;
    }
    // #func: log<T_message>(T_message&&, time_t&), const public generic method
    // #info: logs a message with no log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: StringType T_message, string type of message
    // #overload:
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, time_t&)
    // #param: T_message&& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, reference to current logger instance
    const Logger& Logger::log(const std::string& p_message, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(p_message, std::nullopt, p_time));
        return *this;
    }
    // #func: log<T_message, T_location>(T_message&&, T_location&&, time_t&), const public generic method
    // #info: logs a message with no log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: StringType T_message, string type of message
    // #template: LocationType T_location, location type of source location
    // #overload: 
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, std::source_location&&, time_t&)
    // #param: T_message&& p_message, message to log
    // #param: T_location&& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, reference to current logger instance
    const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, 
    const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(p_message, p_location, p_time));
        return *this;
    }
    // #func: log<T_message>(T_message&&), const public generic method
    const Logger& Logger::log(std::string&& p_message)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log<T_message, T_location>(T_message&&, T_location&&), const public generic method
    const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), p_location, std::nullopt));
        return *this;
    }
    // #func: log<T_message>(T_message&&, time_t&), const public generic method
    const Logger& Logger::log(std::string&& p_message, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), std::nullopt, p_time));
        return *this;
    }
    // #func: log<T_message, T_location>(T_message&&, T_location&&, time_t&), const public generic method
    const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }
    // #func: log<t_logLevel, T_message>(T_message&&), const public generic method
    // #info: logs a message with a log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: Level t_logLevel, log level of the message
    // #template: StringType T_message, string type of message
    // #overload: 
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&)
    // #param: T_message&& p_message, message to log
    // #return: const Logger&, reference to current logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message)const{
        sendLog(formatLog<t_logLevel>(p_message, std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel, T_message, T_location>(T_message&&, T_location&&), const public generic method
    // #info: logs a message with a log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: Level t_logLevel, log level of the message
    // #template: StringType T_message, string type of message
    // #template: LocationType T_location, location type of source location
    // #overload:
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, std::source_location&&)
    // #param: T_message&& p_message, message to log
    // #param: T_location&& p_location, source location of the message
    // #return: const Logger&, reference to current logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<t_logLevel>(p_message, p_location, std::nullopt)); 
        return *this;
    }
    // #func: log<t_logLevel, T_message>(T_message&&, time_t&), const public generic method
    // #info: logs a message with a log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: Level t_logLevel, log level of the message
    // #template: StringType T_message, string type of message
    // #overload:
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, time_t&)
    // #param: T_message&& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, reference to current logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(p_message, std::nullopt, p_time));
        return *this;
    }
    // #func: log<t_logLevel, T_message, T_location>(T_message&&, T_location&&, time_t&), const public generic method
    // #info: logs a message with a log level
    // #note: uses universal reference to handle rvalues and lvalues
    // #scope: Logger, abstract singleton class
    // #template: Level t_logLevel, log level of the message
    // #template: StringType T_message, string type of message
    // #template: LocationType T_location, location type of source location
    // #overload:
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog(Level, std::string&&, std::source_location&&, time_t&)
    // #param: T_message&& p_message, message to log
    // #param: T_location&& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, reference to current logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, 
    const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(p_message, p_location, p_time));
        return *this;
    }
    // #func: log<t_logLevel, T_message>(T_message&&), const public generic method
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel, T_message, T_location>(T_message&&, T_location&&), const public generic method
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), p_location, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel, T_message>(T_message&&, time_t&), const public generic method
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), std::nullopt, p_time));
        return *this;
    }
    // #func: log<t_logLevel, T_message, T_location>(T_message&&, T_location&&, time_t&), const public generic method
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, 
    const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }

// #div: protected factory methods

    // #
    template<StringType T_name> Logger::Logger(T_name&& p_name): m_name(std::forward<T_name>(p_name)), m_formatOrder(deflt::FORMAT_ORDER), 
        m_usesBold(deflt::USES_BOLD){}
    // #
    template<StringType T_name> Logger::Logger(T_name&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder):
        m_name(std::forward<T_name>(p_name)), m_formatOrder(p_formatOrder), m_usesBold(deflt::USES_BOLD){}
    // #
    template<StringType T_name> Logger::Logger(T_name&& p_name, bool p_usesBold): m_name(std::forward<T_name>(p_name)), 
        m_formatOrder(deflt::FORMAT_ORDER), m_usesBold(p_usesBold){}
    // #
    template<StringType T_name> Logger::Logger(T_name&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, bool p_usesBold): 
    m_name(std::forward<T_name>(p_name)), m_formatOrder(p_formatOrder), m_usesBold(p_usesBold){}

// #div: protected methods

    // #func: sendLog(std::string&&), protected virtual method
    // #info: pushes a log to the log stack
    // #note: takes rvalue reference to take ownership of log
    // #note: can be overriden to change what LogStack to use
    // #scope: Logger, abstract singleton class
    // #param: std::string&& p_log, log to push
    void Logger::sendLog(std::string&& p_log)const{
        LogStack::get<AutoFlush>().pushLog(std::forward<std::string>(p_log));
    }
    // #func:
    std::string Logger::formatLogger(const Level p_logLevel)const{
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ansii::RESET;
    }
    // #
    std::string Logger::formatLevel(const Level p_logLevel)const{
        if(m_usesBold){
            return getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + log::SPACE + ansii::RESET;
        }else{
            return getLogColor(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + log::SPACE + ansii::RESET;
        }
    }
    // #
    std::string Logger::formatTime(const Level p_logLevel, const time_t& p_time)const{
        std::tm* time = std::localtime(&p_time);
        return getLogColor(p_logLevel) + log::TIME_BEGIN + std::to_string(time->tm_hour) + log::TIME_SPACE + ((time->tm_min < 10)? "0": "") 
            + std::to_string(time->tm_min) + log::TIME_SPACE + ((time->tm_sec < 10)? "0": "") + std::to_string(time->tm_sec) + log::TIME_END 
            + log::SPACE + ansii::RESET;
    }
    // #
    std::string Logger::formatMessage(const Level p_logLevel, const std::string& p_message)const{
        return getLogColor(p_logLevel) + p_message + log::SPACE + ansii::RESET;
    }
    // #
    std::string Logger::formatMessage(const Level p_logLevel, std::string&& p_message)const{
        return getLogColor(p_logLevel) + std::forward<std::string>(p_message) + log::SPACE + ansii::RESET;
    }
    // #
    std::string Logger::formatLocation(const Level p_logLevel, const std::source_location& p_location)const{
        return getLogColor(p_logLevel) + log::LINE_BEGIN + log::SPACE + std::to_string(p_location.line()) 
            + log::SPACE + p_location.function_name() + log::SPACE + p_location.file_name() + log::SPACE + ansii::RESET;
    }
    // #func: getLogColor(Level), protected virtual method
    // #info: gets the color of the log level
    // #note: can be overriden to change how the log level color is determined
    // #note: relies on RVO to avoid copy
    // #scope: Logger, abstract singleton class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get color for
    // #return: std::string, color of the log level
    std::string Logger::getLogColor(Level p_logLevel)const{
        return log::LEVEL_COLOR.at(p_logLevel);
    }
    // #func: getLogColorBold(Level), protected virtual method
    // #info: gets the bold color of the log level
    // #note: can be overriden to change how the log level bold color is determined
    // #note: relies on RVO to avoid copy
    // #scope: Logger, abstract singleton class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get bold color for
    // #return: std::string, bold color of the log level
    std::string Logger::getLogColorBold(const Level p_logLevel)const{
        return log::LEVEL_COLOR_BOLD.at(p_logLevel);
    }
    // #func: getLogLevelName(Level), protected virtual method
    // #info: gets the name of the log level
    // #note: can be overriden to change how the log level name is determined
    // #note: relies on RVO to avoid copy
    // #scope: Logger, abstract singleton class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get name for
    // #return: std::string, name of the log level
    std::string Logger::getLogLevelName(Level p_logLevel)const{
        return log::LEVEL_NAME.at(p_logLevel);
    }
    // #
    template<Level t_logLevel, StringType T_message> std::string Logger::formatLog(T_message&& p_message,
    const std::optional<std::source_location> p_location, const std::optional<time_t> p_time)const{
        std::string log;
        for(const Format& format: m_formatOrder){
            switch(format){
                case Format::LOGGER: {
                    log += formatLogger(t_logLevel);
                    break;
                }case Format::LEVEL: {
                    if(t_logLevel != Level::NONE){
                        log += formatLevel(t_logLevel);
                    }
                    break;
                }case Format::TIME: {
                    if(p_time.has_value()){
                        log += formatTime(t_logLevel, p_time.value());
                    }
                    break;
                }case Format::MESSAGE: {
                    log += formatMessage(t_logLevel, std::forward<T_message>(p_message));
                    break;
                }case Format::LOCATION: {
                    if(p_location.has_value()){
                        log += formatLocation(t_logLevel, p_location.value());
                    }
                    break;
                } 
            } 
        }
        return log;      
    }

}