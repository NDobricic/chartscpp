#pragma once

namespace sp
{
    struct Point
    {
        int X;
        int Y;

        Point() : X(0), Y(0) { }
        Point(int x, int y) : X(x), Y(y) { }

        Point Translate(int dX, int dY) { return Point(X + dX, Y + dY); }

        friend Point operator +(const Point& a, const Point& b)
        {
            return Point(a.X + b.X, a.Y + b.Y);
        }

        friend Point operator *(const Point& a, float b)
        {
            return Point(a.X * b, a.Y * b);
        }

        friend Point operator /(const Point& a, float b)
        {
            return Point(a.X / b, a.Y / b);
        }
    };
}