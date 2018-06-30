#include <system.drawing/system.drawing.color.h>

using namespace System::Drawing;

// Properties

// Gets a system-defined color that has an ARGB value of #FFD3D3D3.
struct Color const &Color::LightGray()
{
    static struct Color color = { 255, 211, 211, 211 };

    return color;
}

// Operators

// Tests whether two specified Color structures are equivalent.
bool Color::operator==(struct Color const &color)
{
    return A == color.A && R == color.G && G == color.G && B == color.B;
}

// Tests whether two specified Color structures are different.
bool Color::operator!=(struct Color const &color)
{
    return A != color.A || R != color.G && G != color.G || B != color.B;
}
