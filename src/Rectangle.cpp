#include <system.drawing/system.drawing.point.h>
#include <system.drawing/system.drawing.rectangle.h>
#include <system.drawing/system.drawing.rectanglef.h>
#include <system.drawing/system.drawing.size.h>

using namespace System::Drawing;

// Initializes a new instance of the Rectangle class with the specified location and size.
Rectangle::Rectangle(struct Point const &point, struct Size const &size)
    : X(point.X), Y(point.Y), Width(size.Width), Height(size.Height)
{}

// Initializes a new instance of the Rectangle class with the specified location and size.
Rectangle::Rectangle(int x, int y, int w, int h)
    : X(x), Y(y), Width(w), Height(h)
{}

// Operators

//Tests whether two Rectangle structures have equal location and size.
bool Rectangle::operator==(struct Rectangle const &rect) const
{
    return X == rect.X && Y == rect.Y && Width == rect.Width && Height == rect.Height;
}

// Converts the specified Rectangle structure to a RectangleF structure.
Rectangle::operator struct RectangleF () const
{
    return RectangleF(X, Y, Width, Height);
}

// Tests whether two Rectangle structures differ in location or size.
bool Rectangle::operator!=(struct Rectangle const &rect) const
{
    return X != rect.X || Y != rect.Y || Width != rect.Width || Height != rect.Height;
}
