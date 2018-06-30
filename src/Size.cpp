#include <system.drawing/system.drawing.point.h>
#include <system.drawing/system.drawing.size.h>

using namespace System::Drawing;

// Initializes a new instance of the Size structure from the specified dimensions.
Size::Size(int width, int height)
    : Width(width), Height(height)
{}

// Initializes a new instance of the Size structure from the specified Point structure.
Size::Size(struct Point point)
    : Width(point.X), Height(point.Y)
{}

// Operators

// Adds the width and height of one Size structure to the width and height of another Size structure.
struct Size Size::operator+(struct Size const &size) const
{}

// Tests whether two Size structures are equal.
bool Size::operator==(struct Size const &size) const
{}

// Converts the specified Size structure to a Point structure.
Size::operator Point() const
{}

// Converts the specified Size structure to a SizeF structure.
Size::operator SizeF() const
{}

// Tests whether two Size structures are different.
bool Size::operator!=(struct Size const &size) const
{}

// Subtracts the width and height of one Size structure from the width and height of another Size structure.
struct Size Size::operator-(struct Size const &size) const
{
    return Drawing::Size(Width - size.Width, Height - size.Height);
}
