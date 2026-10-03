# Definición de archivos fuente del Motor
set(CORE_SOURCES
    Core/Application.cpp
    Window/Window.cpp
)

set(CORE_HEADERS
    Core/Application.hpp
    Core/Time.hpp
    Window/Window.hpp
)

add_library(AtaraxiaCore STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(AtaraxiaCore PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(AtaraxiaCore PUBLIC SDL2::SDL2)