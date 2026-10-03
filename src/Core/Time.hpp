#ifndef ATARAXIA_TIME_HPP
#define ATARAXIA_TIME_HPP

#include <SDL2/SDL.h>

namespace Ataraxia {

    class Time {
    public:
        static float GetTime() {
            return static_cast<float>(SDL_GetTicks()) / 1000.0f;
        }
    };

} // namespace Ataraxia

#endif // ATARAXIA_TIME_HPP