#ifndef ATARAXIA_KEYCODES_HPP
#define ATARAXIA_KEYCODES_HPP

#include <cstdint>

namespace Ataraxia {

    enum class KeyCode : uint16_t {
        Unknown = 0,
        
        // Letras
        A = 4, B = 5, C = 6, D = 7, E = 8, F = 9, G = 10, H = 11,
        I = 12, J = 13, K = 14, L = 15, M = 16, N = 17, O = 18,
        P = 19, Q = 20, R = 21, S = 22, T = 23, U = 24, V = 25,
        W = 26, X = 27, Y = 28, Z = 29,

        // Números superiores
        Num1 = 30, Num2 = 31, Num3 = 32, Num4 = 33, Num5 = 34,
        Num6 = 35, Num7 = 36, Num8 = 37, Num9 = 38, Num0 = 39,

        // Teclas de control
        Return = 40, Escape = 41, Backspace = 42, Tab = 43, Space = 44,
        Right = 79, Left = 80, Down = 81, Up = 82,
        
        LShift = 225, LCtrl = 224, LAlt = 226
    };

    enum class MouseButton : uint8_t {
        Left = 1,
        Middle = 2,
        Right = 3
    };

} // namespace Ataraxia

#endif // ATARAXIA_KEYCODES_HPP