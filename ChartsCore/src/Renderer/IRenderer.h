#pragma once

#include <vector>

#include "Alignment.h"
#include "Color.h"
#include "Font.h"
#include "Point.h"
#include "Rectangle.h"
#include "Size.h"

namespace sp
{
    class IRenderer
    {
    public:
        bool AntiAlias = false;

        virtual void Clear(const Color& color) = 0;

        virtual void ClipRect(const Rectangle& rect) = 0;
        virtual void ClipReset() = 0;

        virtual void DrawLine(const Point& start, const Point& end, const Color& color, float thickness) = 0;

        virtual void DrawPath(const std::vector<Point>& points, const Color& color, float thickness) = 0;
        virtual void FillPath(const std::vector<Point>& points, const Color& color) = 0;

        virtual void DrawCircle(const Point& center, float radius, const Color& strokeColor, float strokeThickness) = 0;
        virtual void FillCircle(const Point& center, float radius, const Color& fillColor) = 0;

        virtual void DrawRectangle(const Rectangle& rect, const Color& strokeColor, float strokeThickness) = 0;
        virtual void FillRectangle(const Rectangle& rect, const Color& fillColor) = 0;

        virtual void DrawText(const std::string& text, const Font& font, const Point& location, const Color& color) = 0;
        virtual float GetTextWidth(const std::string& text, const Font& font) const = 0;
        virtual float GetTextHeight(const Font& font) const = 0;
    };
}