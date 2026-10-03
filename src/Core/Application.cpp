#include "Application.hpp"
#include "Render/Renderer2D.hpp"
#include "Input/Input.hpp"
#include <iostream>

namespace Ataraxia {

    Application::Application() {
        m_window = std::make_unique<Window>(WindowProps("AtaraxiaCore v0.1.0 - Phase 3 Input", 1280, 720));
        if (!m_window->Init()) {
            m_running = false;
            return;
        }

        if (!Renderer2D::Init(*m_window)) {
            m_running = false;
            return;
        }

        m_lastFrameTime = SDL_GetPerformanceCounter();
    }

    Application::~Application() {
        Renderer2D::Shutdown();
    }

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

        // Posición del jugador de prueba
        float playerX = 100.0f;
        float playerY = 100.0f;
        const float speed = 300.0f; // píxeles por segundo

        while (m_running) {
            uint64_t currentFrameTime = SDL_GetPerformanceCounter();
            m_deltaTime = static_cast<float>(currentFrameTime - m_lastFrameTime) / static_cast<float>(perfFrequency);
            m_lastFrameTime = currentFrameTime;

            ProcessEvents();

            // Tecla Escape para salir
            if (Input::IsKeyPressed(KeyCode::Escape)) {
                m_running = false;
            }

            // Movimiento mediante Input
            if (Input::IsKeyPressed(KeyCode::W)) playerY -= speed * m_deltaTime;
            if (Input::IsKeyPressed(KeyCode::S)) playerY += speed * m_deltaTime;
            if (Input::IsKeyPressed(KeyCode::A)) playerX -= speed * m_deltaTime;
            if (Input::IsKeyPressed(KeyCode::D)) playerX += speed * m_deltaTime;

            // Renderizado
            Renderer2D::SetClearColor(Color::DarkSlate);
            Renderer2D::Clear();

            // Cuadro interactivo movido por WASD
            Color playerColor = Input::IsMouseButtonPressed(MouseButton::Left) ? Color::Green : Color::Red;
            Renderer2D::DrawQuad(static_cast<int>(playerX), static_cast<int>(playerY), 64, 64, playerColor);

            // Cuadro en la posición del puntero
            auto [mouseX, mouseY] = Input::GetMousePosition();
            Renderer2D::DrawQuadOutline(static_cast<int>(mouseX) - 15, static_cast<int>(mouseY) - 15, 30, 30, Color::White);

            Renderer2D::Present();

            if (m_window) {
                m_window->OnUpdate();
            }
        }
    }

    void Application::Close() {
        m_running = false;
    }

} // namespace Ataraxia