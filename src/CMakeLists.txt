# Fuentes de Dear ImGui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui)

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
)

# Fuentes del Motor
set(CORE_SOURCES
    Core/Application.cpp
    Window/Window.cpp
    Render/Renderer2D.cpp
    Render/ImGuiLayer.cpp
    Input/Input.cpp
    ${IMGUI_SOURCES}
)

set(CORE_HEADERS
    Core/Application.hpp
    Core/Time.hpp
    Window/Window.hpp
    Render/Color.hpp
    Render/Renderer2D.hpp
    Render/ImGuiLayer.hpp
    Input/KeyCodes.hpp
    Input/Input.hpp
)

add_library(AtaraxiaCore STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(AtaraxiaCore PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(AtaraxiaCore PUBLIC SDL2::SDL2)