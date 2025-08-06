# Prototype of a CMAKELIST

cmake_minimum_required(VERSION 3.5)
project(Quantum C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncursesw")
include_directories(HEADER_FILE)
file(GLOB MAIN 
    "main.c"
    "variables.h"
)
set(MAIN main.c)
message(STATUS "Checking For Ncurses")
find_package(Curses REQUIRED)
if (NOT Curses_FOUND)
    message(STATUS "Ncurses Not Found")
    message(FATAL_ERROR "Please Install it by the name libncurses, ncurses or similar")
endif()

find_path(FONT_PATH
NAMES SymbolsNerdFont-Regular.ttf
SymbolsNerdFontMono-Regular.ttf

PATHS /usr/share/fonts/truetype/nerd-fonts
    /usr/share/fonts
    /usr/share/fonts/TTF
PATH_SUFFIXES nerd-fonts
)
if(NOT FONT_PATH)
    message(WARNING "Fonts not found, attempting package installation.")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_SOURCE_DIR}/fonts ./installfonts.sh
        RESULT_VARIABLE INSTALL_RESULT
    )
    if(NOT INSTALL_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to execute installfonts.sh.")
    endif()
    
endif()


add_executable(Quantum main.c)
install(TARGETS Quantum DESTINATION /usr/local/bin)
add_custom_command(   
    TARGET Quantum POST_BUILD
    
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Quantum> /usr/bin/
    COMMAND ${CMAKE_COMMAND} -E echo "alias Quantum=/usr/bin/Quantum" >> $ENV{HOME}~/.bashrc  
)

