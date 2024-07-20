cmake_minimum_required(VERSION 3.29)
project(BetterLogger VERSION 1.9 DESCRIPTION "A better Logger for C++"  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set environment variables
set(ROOT_DIR ${CMAKE_SOURCE_DIR}/..)
set(INCLUDE ${ROOT_DIR}/include)
set(LIB_INCLUDE ${ROOT_DIR}/lib_include)
# set library
add_library(BetterLoggerLib INTERFACE)
target_precompile_headers(BetterLoggerLib INTERFACE ${LIB_INCLUDE}/better/logger.hpp)
target_include_directories(BetterLoggerLib INTERFACE ${LIB_INCLUDE})
# set tester
add_executable(Tester ${ROOT_DIR}/tester/tester.cpp)
target_link_libraries(Tester PRIVATE BetterLoggerLib)
target_include_directories(Tester PRIVATE ${LIB_INCLUDE})
set_target_properties(Tester PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/tester)
