cmake_minimum_required(VERSION 3.16)
project(AtaraxiaEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opciones de compilación estrictas
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Intentar buscar SDL2 por Config nativo de CMake
find_package(SDL2 QUIET)

# Si no lo encuentra, buscar mediante PkgConfig (común en Linux/Arch)
if(NOT SDL2_FOUND)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    
    # Crear target importado si no existe
    if(NOT TARGET SDL2::SDL2)
        add_library(SDL2::SDL2 INTERFACE IMPORTED)
        target_include_directories(SDL2::SDL2 INTERFACE ${SDL2_INCLUDE_DIRS})
        target_link_libraries(SDL2::SDL2 INTERFACE ${SDL2_LIBRARIES})
        target_compile_options(SDL2::SDL2 INTERFACE ${SDL2_CFLAGS_OTHER})
    endif()
endif()

# Incluir subdirectorios
add_subdirectory(src)
add_subdirectory(sandbox)