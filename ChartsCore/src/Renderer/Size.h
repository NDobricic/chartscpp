#pragma once

namespace sp
{
    struct Size
    {
        int Width;
        int Height;

        Size() : Width(0), Height(0) { }
        Size(int width, int height) : Width(width), Height(height) { }
    };
}