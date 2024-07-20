
#include "better/logger.hpp"

class HazelDebug: public better::Logger{
public:
    HazelDebug(): Logger("HazelDebug"){}
};



int main(){
    system("cls");


    better::Logger::get<better::Main>().log("default log from default logger");
    better::Logger::get<better::Debug>().log("default log from default logger");
    better::Logger::get<HazelDebug>().log("default log from special logger");

    better::Logger::get<HazelDebug>().log<better::log::Level::INFO>("heres some info for you cuh", better::Help::getCurrentTime());
    better::Logger::get<HazelDebug>().log<better::log::Level::TRACE>("heres some trace for you cuh", better::Help::getCurrentLocation());
    better::Logger::get<HazelDebug>().log<better::log::Level::WARN>("hey watch out buddy dont wanna get hurt");
    better::Logger::get<HazelDebug>().log<better::log::Level::ERR>("oh no you messed up", better::Help::getCurrentLocation(), better::Help::getCurrentTime());
    better::Logger::get<HazelDebug>().log<better::log::Level::CRIT>("oh no you really messed up fuck tard", better::Help::getCurrentLocation());

    better::LogStack::get().flush();

    system("pause");
    return 0;
}