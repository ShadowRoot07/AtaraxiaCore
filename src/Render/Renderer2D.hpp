#ifndef ATARAXIA_RENDERER2D_HPP
#define ATARAXIA_RENDERER2D_HPP

#include "Color.hpp"
#include <SDL2/SDL.h>

namespace Ataraxia {

    class Window;

    class Renderer2D {
    public:
        static bool Init(Window& window);
        static void Shutdown();

        static void SetClearColor(const Color& color);
        static void Clear();
        static void Present();

        // Primitivas de renderizado
        static void DrawQuad(int x, int y, int width, int height, const Color& color);
        static void DrawQuadOutline(int x, int y, int width, int height, const Color& color);

        [[nodiscard]] static SDL_Renderer* GetNativeRenderer() { return s_renderer; }

    private:
        static SDL_Renderer* s_renderer;
        static Color s_clearColor;
    };

} // namespace Ataraxia

#endif // ATARAXIA_RENDERER2D_HPP