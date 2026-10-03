set(CORE_SOURCES
    Core/Application.cpp
    Window/Window.cpp
    Render/Renderer2D.cpp
    Input/Input.cpp
)

set(CORE_HEADERS
    Core/Application.hpp
    Core/Time.hpp
    Window/Window.hpp
    Render/Color.hpp
    Render/Renderer2D.hpp
    Input/KeyCodes.hpp
    Input/Input.hpp
)

add_library(AtaraxiaCore STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(AtaraxiaCore PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(AtaraxiaCore PUBLIC SDL2::SDL2)