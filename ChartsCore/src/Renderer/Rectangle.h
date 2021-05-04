#pragma once

namespace sp
{
    struct Rectangle
    {
        int Left;
        int Top;
        int Right;
        int Bottom;

        int Width() { return Right - Left + 1; }
        int Height() { return Bottom - Top + 1; }

        Rectangle(int left, int top, int right, int bottom)
            : Left(left), Top(top), Right(right), Bottom(bottom) { }

        Rectangle() : Rectangle(0, 0, 0, 0) { }
    };
}