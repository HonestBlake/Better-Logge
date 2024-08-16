#pragma once

#include "header/logStacks.hpp"

namespace worTech::betterLogger::logStacks{

// --------------------------------
// #div: LogStack, singleton class
// --------------------------------

// #div: public factory methods

    // #
    LogStack::~LogStack(){
        flush();
    }

// #div: public static methods

    // #
    template<class T_derived> LogStack& LogStack::get(){
        static T_derived instance = T_derived();
        return instance;
    }

// #div: public methods

    // #
    LogStack& LogStack::pushLog(const std::string& p_log){
        m_logBuffer.push_back(p_log);
        autoFlush();
        return *this;
    }
    // #
    LogStack& LogStack::pushLog(std::string&& p_log){
        m_logBuffer.push_back(std::forward<std::string>(p_log));
        autoFlush();
        return *this;
    }
    // #
    LogStack& LogStack::flush(){
        for(std::string& log: m_logBuffer){
            recordLog(std::move(log));
        }
        m_logBuffer.clear();
        return *this;
    }

// #div: protected methods

    // #
    void LogStack::autoFlush(){
        flush();
    }
    // #
    void LogStack::recordLog(std::string&& p_log){
        std::cout << p_log << std::endl;
    }

}