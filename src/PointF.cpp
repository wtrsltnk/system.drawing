#include <system.drawing/system.drawing.pointf.h>
#include <system.drawing/system.drawing.size.h>
#include <system.drawing/system.drawing.sizef.h>

using namespace System::Drawing;

// Initializes a new instance of the PointF class with the specified coordinates.
PointF::PointF(float x, float y)
    : X(x), Y(y)
{}

// Gets a value indicating whether this PointF is empty.
bool PointF::IsEmpty() const
{
    return X == 0 && Y == 0;
}

// Translates a given PointF by the specified Size.
struct PointF PointF::Add(struct PointF const &point, struct Size const &size)
{
    return Drawing::PointF(float(point.X + size.Width), float(point.Y + size.Height));
}

// Translates a given PointF by a specified SizeF.
struct PointF PointF::Add(struct PointF const &point, struct SizeF const &size)
{
    return Drawing::PointF(point.X + size.Width, point.Y + size.Height);
}

// Translates a PointF by the negative of a specified size.
struct PointF PointF::Subtract(struct PointF const &point, struct Size const &size)
{
    return Drawing::PointF(float(point.X - size.Width), float(point.Y - size.Height));
}

// Translates a PointF by the negative of a specified size.
struct PointF PointF::Subtract(struct PointF const &point, struct SizeF const &size)
{
    return Drawing::PointF(point.X - size.Width, point.Y - size.Height);
}

// Operators

// Translates a PointF by a given Size.
struct PointF PointF::operator+(struct Size const &size) const
{
    return PointF(X + size.Width, Y + size.Height);
}

// Translates the PointF by the specified SizeF.
struct PointF PointF::operator+(struct SizeF const &size) const
{
    return PointF(X + size.Width, Y + size.Height);
}

// Compares two PointF structures. The result specifies whether the values of the X and Y properties of the two PointF structures are equal.
bool PointF::operator==(struct PointF const &point) const
{
    return X == point.X && Y == point.Y;
}

// Determines whether the coordinates of the specified points are not equal.
bool PointF::operator!=(struct PointF const &point) const
{
    return X != point.X || Y != point.Y;
}

// Translates a PointF by the negative of a given Size.
struct PointF PointF::operator-(struct Size const &size) const
{
    return PointF(X - size.Width, Y - size.Height);
}

// Translates a PointF by the negative of a specified SizeF.
struct PointF PointF::operator-(struct SizeF const &size) const
{
    return PointF(X - size.Width, Y - size.Height);
}
