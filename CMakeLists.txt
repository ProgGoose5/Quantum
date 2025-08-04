cmake_minimum_required(VERSION 3.20)
project(Quantum C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncursesw")
include_directories(HEADER_FILE)
file(GLOB MAIN 
    "main.c"
    "variables.h"
)

message(STATUS "Checking For Ncurses")
find_package(Curses REQUIRED)
if (NOT Curses_FOUND)
    message(STATUS "Ncurses Not Found")
    message(FATAL_ERROR "Please Install it by the name libncurses, ncurses or similar")
endif()


add_executable(Quantum ${MAIN}) 
add_custom_command(
    TARGET Quantum POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Quantum> /usr/bin/
    COMMAND ${CMAKE_COMMAND} -E echo "alias Quantum=/usr/bin/Quantum" >> $ENV{HOME}~/.bashrc  
)
