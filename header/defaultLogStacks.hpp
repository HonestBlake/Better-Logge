#pragma once

// #

#include "betterLogger.hpp"

#include "logStacks.hpp"

namespace worTech::betterLogger::defaultLogStacks{

    // #class: DefaultAutoFlush, singleton class
    class AutoFlush: public LogStack{};
    // #class: DefaultTerminateFlush, singleton class
    class TerminateFlush: public LogStack{
    private:
        void autoFlush() override;
    };

}