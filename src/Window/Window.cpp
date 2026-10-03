#include "Window.hpp"
#include <iostream>

namespace Ataraxia {

    Window::Window(const WindowProps& props) {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;
    }

    Window::~Window() {
        Shutdown();
    }

    bool Window::Init() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
            std::cerr << "[ERROR] Fallo al inicializar SDL2: " << SDL_GetError() << std::endl;
            return false;
        }

        m_window = SDL_CreateWindow(
            m_data.title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            static_cast<int>(m_data.width),
            static_cast<int>(m_data.height),
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
        );

        if (!m_window) {
            std::cerr << "[ERROR] No se pudo crear la ventana SDL2: " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    void Window::Shutdown() {
        if (m_window) {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
        SDL_Quit();
    }

    void Window::OnUpdate() {
        // Reservado para SWAP BUFFERS o eventos del contexto gráfico
    }

} // namespace Ataraxia