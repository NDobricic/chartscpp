#pragma once

#include <string>
#include "Alignment.h"

namespace sp
{
    struct Font
    {
        std::string Name;
        float Size;

        HorizontalAlignment HAlignment = HorizontalAlignment::Left;
        VerticalAlignment VAlignment = VerticalAlignment::Bottom;

        Font(const std::string& fontName, float fontSize,
            const HorizontalAlignment& hAlign = HorizontalAlignment::Left,
            const VerticalAlignment& vAlign = VerticalAlignment::Top)
        {
            Name = fontName;
            Size = fontSize;
            HAlignment = hAlign;
            VAlignment = vAlign;
        }
    };
}