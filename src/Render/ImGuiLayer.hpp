#ifndef ATARAXIA_IMGUILAYER_HPP
#define ATARAXIA_IMGUILAYER_HPP

#include <SDL2/SDL.h>

namespace Ataraxia {

    class Window;

    class ImGuiLayer {
    public:
        static bool Init(Window& window);
        static void Shutdown();

        static void ProcessEvent(const SDL_Event* event);
        static void BeginFrame();
        static void EndFrame();
    };

} // namespace Ataraxia

#endif // ATARAXIA_IMGUILAYER_HPP