cmake_minimum_required(VERSION 3.0)
project(Quantum C)
set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NERD_FONT REQUIRED nerd-fonts-symbols-mono)
include_directories(${NERD_FONT_INCLUDE_DIRS})
link_directories(${NERD_FONT_LIBRARY_DIRS})
add_definitions(${NERD_FONT_CFLAGS_OTHER})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Quantum ${CURSES_LIBRARIES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lncursesw")
include_directories(HEADER_FILE)
file(GLOB MAIN 
    "main.c"
    "variables.h"
)

add_executable(Quantum ${MAIN}) 
add_custom_command(
    TARGET Quantum POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Quantum> /usr/bin/
    COMMAND ${CMAKE_COMMAND} -E echo "alias Quantum=/usr/bin/Quantum" >> $ENV{HOME}~/.bashrc  
)
