#ifndef ATARAXIA_INPUT_HPP
#define ATARAXIA_INPUT_HPP

#include "KeyCodes.hpp"
#include <utility>

namespace Ataraxia {

    class Input {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseButton button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };

} // namespace Ataraxia

#endif // ATARAXIA_INPUT_HPP