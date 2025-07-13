# Prototype of a CMAKELIST

cmake_minimum_required(VERSION 3.5)
project(Quantum C)
set(C_MAKE_STANDART 99)

#Searching the fonts
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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncursesw")
add_executable(Quantum main.c)
install(TARGETS Quantum DESTINATION /usr/local/bin)
