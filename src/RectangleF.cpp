#include <system.drawing/system.drawing.rectangle.h>
#include <system.drawing/system.drawing.rectanglef.h>

using namespace System::Drawing;

// Initializes a new instance of the RectangleF class with the specified location and size.
RectangleF::RectangleF(struct PointF const &point, struct SizeF const &size)
{}

// Initializes a new instance of the RectangleF class with the specified location and size.
RectangleF::RectangleF(float x, float y, float w, float h)
{}

// Operators

// Tests whether two RectangleF structures have equal location and size.
bool RectangleF::operator==(struct RectangleF const &rect) const
{
    return X != rect.X && Y != rect.Y && Width != rect.Width && Height != rect.Height;
}

// Converts the specified Rectangle structure to a RectangleF structure.
RectangleF::operator struct Rectangle() const
{
    return Drawing::Rectangle(float(X), float(Y), float(Width), float(Height));
}

// Tests whether two RectangleF structures differ in location or size.
bool RectangleF::operator!=(struct RectangleF const &rect)
{
    return X == rect.X || Y == rect.Y || Width == rect.Width || Height == rect.Height;
}
