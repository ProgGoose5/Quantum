cmake_minimum_required(VERSION 3.0)
project(Quantum C)
set(CMAKE_C_STANDARD 99)
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

# Ensure ttf-nerd-fonts-symbols-mono is installed
find_program(FONT_CHECK ttf-nerd-fonts-symbols-mono)
if(NOT FONT_CHECK)
    message(STATUS "ttf-nerd-fonts-symbols-mono not found. Attempting to install it.")
    if(EXISTS "/etc/debian_version")
        execute_process(COMMAND sudo apt-get install -y ttf-nerd-fonts-symbols-mono
                        RESULT_VARIABLE FONT_INSTALL_RESULT)
    elseif(EXISTS "/etc/fedora-release")
        execute_process(COMMAND sudo dnf install -y ttf-nerd-fonts-symbols-mono
                        RESULT_VARIABLE FONT_INSTALL_RESULT)
    elseif(EXISTS "/etc/arch-release")
        execute_process(COMMAND sudo pacman -S --noconfirm ttf-nerd-fonts-symbols-mono
                        RESULT_VARIABLE FONT_INSTALL_RESULT)
    elseif(EXISTS "/etc/alpine-release")
        execute_process(COMMAND sudo apk add ttf-nerd-fonts-symbols-mono
                        RESULT_VARIABLE FONT_INSTALL_RESULT)
    else()
        message(FATAL_ERROR "Unsupported distribution. Please install ttf-nerd-fonts-symbols-mono manually.")
    endif()
    if(NOT FONT_INSTALL_RESULT EQUAL "0")
        message(FATAL_ERROR "Failed to install ttf-nerd-fonts-symbols-mono. Please install it manually.")
    endif()

endif()
