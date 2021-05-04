#pragma once

#include <cstdint>
#include <random>
#include <string>
#include <stdexcept>
#include <assert.h>

namespace sp
{
    struct Color
    {
        uint8_t R;
        uint8_t G;
        uint8_t B;
        uint8_t A;

        static constexpr Color red() { return Color(255, 0, 0); }
        static constexpr Color green() { return Color(0, 255, 0); }
        static constexpr Color blue() { return Color(0, 0, 255); }
        static constexpr Color black() { return Color(0, 0, 0); }
        static constexpr Color white() { return Color(255, 255, 255); }

        constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
            : R(r), G(g), B(b), A(a)
        { }

        static Color Random(int seed)
        {
            srand(seed);
            return Color(rand() % 256, rand() % 256, rand() % 256);
        }
        static Color Random() { return Random(rand()); }

        static constexpr Color FromRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { return Color(r, g, b, a); }
        static constexpr Color FromRGBA(Color color, uint8_t a) { return Color(color.R, color.G, color.B, a); }

        static Color FromHex(std::string hex)
        {
            if (hex[0] == '#')
                hex.erase(hex.begin());

            assert(hex.length() == 6 || hex.length() == 8);

            if (hex.length() == 6)
            {
                return FromRGBA(255,
                    stoi(hex.substr(0, 2), nullptr, 16),
                    stoi(hex.substr(2, 2), nullptr, 16),
                    stoi(hex.substr(4, 2), nullptr, 16));
            }
            else //hex.length() == 8
            {
                return FromRGBA(stoi(hex.substr(0, 2), nullptr, 16),
                    stoi(hex.substr(2, 2), nullptr, 16),
                    stoi(hex.substr(4, 2), nullptr, 16),
                    stoi(hex.substr(6, 2), nullptr, 16));
            }
        }
    };
}
