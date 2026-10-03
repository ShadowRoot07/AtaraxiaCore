#ifndef ATARAXIA_APPLICATION_HPP
#define ATARAXIA_APPLICATION_HPP

#include "Window/Window.hpp"
#include <memory>

namespace Ataraxia {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
        void Close();

    private:
        void ProcessEvents();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running{true};
        
        uint64_t m_lastFrameTime{0};
        float m_deltaTime{0.0f};
    };

} // namespace Ataraxia

#endif // ATARAXIA_APPLICATION_HPP