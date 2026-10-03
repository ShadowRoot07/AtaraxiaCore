#include "ImGuiLayer.hpp"
#include "Window/Window.hpp"
#include "Renderer2D.hpp"

#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <iostream>

namespace Ataraxia {

    bool ImGuiLayer::Init(Window& window) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Habilitar navegación por teclado
//      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Habilitar Docking para el editor

        // Estilo visual del editor
        ImGui::StyleColorsDark();

        SDL_Window* nativeWin = window.GetNativeWindow();
        SDL_Renderer* nativeRenderer = Renderer2D::GetNativeRenderer();

        if (!ImGui_ImplSDL2_InitForSDLRenderer(nativeWin, nativeRenderer)) {
            std::cerr << "[ERROR] Fallo al inicializar ImGui SDL2 Backend." << std::endl;
            return false;
        }

        if (!ImGui_ImplSDLRenderer2_Init(nativeRenderer)) {
            std::cerr << "[ERROR] Fallo al inicializar ImGui SDLRenderer2 Backend." << std::endl;
            return false;
        }

        std::cout << "[INFO] ImGuiLayer inicializado correctamente." << std::endl;
        return true;
    }

    void ImGuiLayer::Shutdown() {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::ProcessEvent(const SDL_Event* event) {
        ImGui_ImplSDL2_ProcessEvent(event);
    }

    void ImGuiLayer::BeginFrame() {
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::EndFrame() {
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), Renderer2D::GetNativeRenderer());
    }

} // namespace Ataraxia