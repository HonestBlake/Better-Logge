#pragma once

// #

#include "betterLogger.hpp"

namespace worTech::betterLogger::logStacks{

    // #class: LogStack, abstract singleton class
    class LogStack{
    public:
    // #div: public factory methods
        virtual ~LogStack();
    // #div: public static methods
        template<class T_derived> static LogStack& get();
    // #div: public methods
        LogStack& pushLog(const std::string& p_log);
        LogStack& pushLog(std::string&& p_log);
        LogStack& flush();
    protected:
    // #div: protected factory methods
        LogStack(const LogStack&) = delete;
        LogStack(LogStack&&) = delete;
        LogStack() = default;
    // #div: protected operators
        LogStack& operator=(const LogStack&) = delete;
        LogStack& operator=(LogStack&&) = delete;
    // #div: protected members
        std::vector<std::string> m_logBuffer;
    // #div: protected methods
        virtual void autoFlush();
        virtual void recordLog(std::string&& p_log);
    };

}