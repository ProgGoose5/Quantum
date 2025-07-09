cmake_minimum_required(VERSION 3.20)
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
        if(NOT DEFINED ENV{SUDO_USER})
            message(FATAL_ERROR "Please run cmake with sudo to install ttf-nerd-fonts-symbols-mono.")
        endif()
        if(NOT DEFINED ENV{SUDO_USER})
            message(FATAL_ERROR "Please run cmake with sudo to install ttf-nerd-fonts-symbols-mono.")
        endif()
        if(NOT DEFINED ENV{SUDO_USER})
            message(FATAL_ERROR "Please run cmake with sudo to install ttf-nerd-fonts-symbols-mono.")
        endif()
        if(NOT DEFINED ENV{SUDO_USER})
            message(FATAL_ERROR "Please run cmake with sudo to install ttf-nerd-fonts-symbols-mono.")
        endif()
        execute_process(COMMAND apk add ttf-nerd-fonts-symbols-mono
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
    elseif(EXISTS "/etc/linuxmint/info")
        execute_process(COMMAND sudo apt-get install -y wget unzip
                RESULT_VARIABLE DEPENDENCY_INSTALL_RESULT)
        if(NOT DEPENDENCY_INSTALL_RESULT EQUAL "0")
            message(FATAL_ERROR "Failed to install wget and unzip. Please install them manually.")
        endif()
        execute_process(COMMAND wget -q https://github.com/ryanoasis/nerd-fonts/releases/download/v2.3.3/NerdFontsSymbolsOnly.zip -O /tmp/NerdFontsSymbolsOnly.zip
                RESULT_VARIABLE DOWNLOAD_RESULT)
        if(NOT DOWNLOAD_RESULT EQUAL "0")
            message(FATAL_ERROR "Failed to download Nerd Fonts Symbols. Please download it manually from https://github.com/ryanoasis/nerd-fonts/releases.")
        endif()
        execute_process(COMMAND unzip -o /tmp/NerdFontsSymbolsOnly.zip -d /usr/share/fonts
                RESULT_VARIABLE UNZIP_RESULT)
        if(NOT UNZIP_RESULT EQUAL "0")
            message(FATAL_ERROR "Failed to unzip Nerd Fonts Symbols. Please unzip it manually.")
        endif()
        execute_process(COMMAND fc-cache -fv
                RESULT_VARIABLE FONT_CACHE_RESULT)
        if(NOT FONT_CACHE_RESULT EQUAL "0")
            message(FATAL_ERROR "Failed to update font cache. Please run 'fc-cache -fv' manually.")
        endif()
    endif()

endif()
