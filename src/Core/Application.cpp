#include "Application.hpp"
#include "Render/Renderer2D.hpp"
#include "Render/ImGuiLayer.hpp"
#include "Input/Input.hpp"
#include <imgui.h>
#include <iostream>

namespace Ataraxia {

    Application::Application() {
        m_window = std::make_unique<Window>(WindowProps("AtaraxiaCore v0.1.0 - Phase 4 ImGui", 1280, 720));
        if (!m_window->Init()) {
            m_running = false;
            return;
        }

        if (!Renderer2D::Init(*m_window)) {
            m_running = false;
            return;
        }

        if (!ImGuiLayer::Init(*m_window)) {
            m_running = false;
            return;
        }

        m_lastFrameTime = SDL_GetPerformanceCounter();
    }

    Application::~Application() {
        ImGuiLayer::Shutdown();
        Renderer2D::Shutdown();
    }

    void Application::ProcessEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // Pasar eventos a ImGui
            ImGuiLayer::ProcessEvent(&event);

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

        float clearColor[3] = { 0.11f, 0.11f, 0.13f };

        while (m_running) {
            uint64_t currentFrameTime = SDL_GetPerformanceCounter();
            m_deltaTime = static_cast<float>(currentFrameTime - m_lastFrameTime) / static_cast<float>(perfFrequency);
            m_lastFrameTime = currentFrameTime;

            ProcessEvents();

            if (Input::IsKeyPressed(KeyCode::Escape)) {
                m_running = false;
            }

            // Renderizado del Escena
            Renderer2D::SetClearColor(Color::FromFloat(clearColor[0], clearColor[1], clearColor[2]));
            Renderer2D::Clear();

            // Inicio de Frame ImGui
            ImGuiLayer::BeginFrame();

            // Panel de Control / Editor
            ImGui::Begin("AtaraxiaCore Inspector");
            ImGui::Text("Rendimiento:");
            ImGui::Text("FPS: %.1f", 1.0f / (m_deltaTime > 0.0001f ? m_deltaTime : 0.016f));
            ImGui::Text("Frame Time: %.3f ms", m_deltaTime * 1000.0f);
            
            ImGui::Separator();
            ImGui::ColorEdit3("Color de Fondo", clearColor);
            ImGui::End();

            // Renderizar la GUI sobre la escena
            ImGuiLayer::EndFrame();

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