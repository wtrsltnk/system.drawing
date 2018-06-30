#include <system.drawing/system.drawing.pointf.h>
#include <system.drawing/system.drawing.sizef.h>

using namespace System::Drawing;

// Initializes a new instance of the SizeF structure from the specified PointF structure.
SizeF::SizeF(struct PointF const &point)
    : Width(point.X), Height(point.Y)
{}

// Initializes a new instance of the SizeF structure from the specified dimensions.
SizeF::SizeF(float w, float h)
    : Width(w), Height(h)
{}

// Initializes a new instance of the SizeF structure from the specified existing SizeF structure.
SizeF::SizeF(struct SizeF const &size)
    : Width(size.Width), Height(size.Height)
{}

// Operators

// Adds the width and height of one SizeF structure to the width and height of another SizeF structure.
SizeF SizeF::operator+(struct SizeF const &size) const
{
    return Drawing::SizeF(Width + size.Width, Height + size.Height);
}

// Tests whether two SizeF structures are equal.
bool SizeF::operator==(struct SizeF const &size) const
{
    return Width == size.Width && Height == size.Height;
}

// Converts the specified SizeF structure to a PointF structure.
SizeF::operator struct PointF() const
{
    return Drawing::PointF(Width, Height);
}

// Tests whether two SizeF structures are different.
bool SizeF::operator!=(struct SizeF const &size)
{
    return Width != size.Width || Height != size.Height;
}

// Subtracts the width and height of one SizeF structure from the width and height of another SizeF structure.
struct SizeF SizeF::operator-(struct SizeF const &size)
{
    return Drawing::SizeF(Width - size.Width, Height - size.Height);
}
