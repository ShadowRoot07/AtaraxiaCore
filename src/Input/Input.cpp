#include "Input.hpp"
#include <SDL2/SDL.h>

namespace Ataraxia {

    bool Input::IsKeyPressed(KeyCode key) {
        const uint8_t* state = SDL_GetKeyboardState(nullptr);
        auto sdlScancode = static_cast<SDL_Scancode>(key);
        return state[sdlScancode] != 0;
    }

    bool Input::IsMouseButtonPressed(MouseButton button) {
        uint32_t state = SDL_GetMouseState(nullptr, nullptr);
        uint32_t mask = SDL_BUTTON(static_cast<int>(button));
        return (state & mask) != 0;
    }

    std::pair<float, float> Input::GetMousePosition() {
        int x, y;
        SDL_GetMouseState(&x, &y);
        return { static_cast<float>(x), static_cast<float>(y) };
    }

    float Input::GetMouseX() {
        auto [x, y] = GetMousePosition();
        return x;
    }

    float Input::GetMouseY() {
        auto [x, y] = GetMousePosition();
        return y;
    }

} // namespace Ataraxia