#include "Application.hpp"
#include <iostream>

namespace Ataraxia {

    Application::Application() {
        m_window = std::make_unique<Window>(WindowProps("AtaraxiaCore v0.1.0", 1280, 720));
        if (!m_window->Init()) {
            m_running = false;
        }
        m_lastFrameTime = SDL_GetPerformanceCounter();
    }

    Application::~Application() = default;

    void Application::ProcessEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_running = false;
            }
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    m_running = false;
                }
            }
        }
    }

    void Application::Run() {
        const uint64_t perfFrequency = SDL_GetPerformanceFrequency();

        while (m_running) {
            // Cálculo de Delta Time
            uint64_t currentFrameTime = SDL_GetPerformanceCounter();
            m_deltaTime = static_cast<float>(currentFrameTime - m_lastFrameTime) / static_cast<float>(perfFrequency);
            m_lastFrameTime = currentFrameTime;

            ProcessEvents();
            
            if (m_window) {
                m_window->OnUpdate();
            }

            // Cap básico a ~60 FPS para no saturar la CPU
            SDL_Delay(16); 
        }
    }

    void Application::Close() {
        m_running = false;
    }

} // namespace Ataraxia