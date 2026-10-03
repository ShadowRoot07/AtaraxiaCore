#include "Renderer2D.hpp"
#include "Window/Window.hpp"
#include <iostream>

namespace Ataraxia {

    SDL_Renderer* Renderer2D::s_renderer = nullptr;
    Color Renderer2D::s_clearColor = Color::DarkSlate;

    bool Renderer2D::Init(Window& window) {
        if (s_renderer) {
            std::cout << "[WARN] Renderer2D ya estaba inicializado." << std::endl;
            return true;
        }

        // Creamos el renderer con aceleración por hardware y VSync activado
        s_renderer = SDL_CreateRenderer(
            window.GetNativeWindow(),
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        if (!s_renderer) {
            std::cerr << "[ERROR] Fallo al crear SDL_Renderer: " << SDL_GetError() << std::endl;
            return false;
        }

        // Habilitar mezcla alpha para transparencias
        SDL_SetRenderDrawBlendMode(s_renderer, SDL_BLENDMODE_BLEND);

        std::cout << "[INFO] Renderer2D inicializado correctamente." << std::endl;
        return true;
    }

    void Renderer2D::Shutdown() {
        if (s_renderer) {
            SDL_DestroyRenderer(s_renderer);
            s_renderer = nullptr;
        }
    }

    void Renderer2D::SetClearColor(const Color& color) {
        s_clearColor = color;
    }

    void Renderer2D::Clear() {
        if (!s_renderer) return;
        SDL_SetRenderDrawColor(s_renderer, s_clearColor.r, s_clearColor.g, s_clearColor.b, s_clearColor.a);
        SDL_RenderClear(s_renderer);
    }

    void Renderer2D::Present() {
        if (!s_renderer) return;
        SDL_RenderPresent(s_renderer);
    }

    void Renderer2D::DrawQuad(int x, int y, int width, int height, const Color& color) {
        if (!s_renderer) return;

        SDL_Rect rect{ x, y, width, height };
        SDL_SetRenderDrawColor(s_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(s_renderer, &rect);
    }

    void Renderer2D::DrawQuadOutline(int x, int y, int width, int height, const Color& color) {
        if (!s_renderer) return;

        SDL_Rect rect{ x, y, width, height };
        SDL_SetRenderDrawColor(s_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(s_renderer, &rect);
    }

} // namespace Ataraxia