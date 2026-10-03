#ifndef ATARAXIA_COLOR_HPP
#define ATARAXIA_COLOR_HPP

#include <cstdint>

namespace Ataraxia {

    struct Color {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};
        uint8_t a{255};

        constexpr Color() = default;
        constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
            : r(red), g(green), b(blue), a(alpha) {}

        // Utilidades con floats [0.0f, 1.0f]
        static constexpr Color FromFloat(float red, float green, float blue, float alpha = 1.0f) {
            return Color(
                static_cast<uint8_t>(red * 255.0f),
                static_cast<uint8_t>(green * 255.0f),
                static_cast<uint8_t>(blue * 255.0f),
                static_cast<uint8_t>(alpha * 255.0f)
            );
        }

        // Colores predefinidos útiles
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color DarkSlate;
    };

    inline constexpr Color Color::Black{0, 0, 0, 255};
    inline constexpr Color Color::White{255, 255, 255, 255};
    inline constexpr Color Color::Red{255, 0, 0, 255};
    inline constexpr Color Color::Green{0, 255, 0, 255};
    inline constexpr Color Color::Blue{0, 0, 255, 255};
    inline constexpr Color Color::DarkSlate{30, 30, 35, 255};

} // namespace Ataraxia

#endif // ATARAXIA_COLOR_HPP