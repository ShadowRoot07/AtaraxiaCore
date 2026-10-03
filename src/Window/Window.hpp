#ifndef ATARAXIA_WINDOW_HPP
#define ATARAXIA_WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>

namespace Ataraxia {

    struct WindowProps {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProps(const std::string& t = "AtaraxiaCore Engine", uint32_t w = 1280, uint32_t h = 720)
            : title(t), width(w), height(h) {}
    };

    class Window {
    public:
        explicit Window(const WindowProps& props = WindowProps());
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        bool Init();
        void Shutdown();
        void OnUpdate();

        [[nodiscard]] uint32_t GetWidth() const { return m_data.width; }
        [[nodiscard]] uint32_t GetHeight() const { return m_data.height; }
        [[nodiscard]] SDL_Window* GetNativeWindow() const { return m_window; }

    private:
        SDL_Window* m_window{nullptr};
        
        struct WindowData {
            std::string title;
            uint32_t width;
            uint32_t height;
        } m_data;
    };

} // namespace Ataraxia

#endif // ATARAXIA_WINDOW_HPP