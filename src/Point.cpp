#include <system.drawing/system.drawing.point.h>
#include <system.drawing/system.drawing.pointf.h>
#include <system.drawing/system.drawing.size.h>

using namespace System::Drawing;

// Initializes a new instance of the Point class using coordinates specified by an integer value.
Point::Point(int dw)
    : X(dw), Y(dw)
{}

// Initializes a new instance of the Point class with the specified coordinates.
Point::Point(int x, int y)
    : X(x), Y(y)
{}

// Initializes a new instance of the Point class from a Size.
Point::Point(struct Size const &size)
    : X(size.Width), Y(size.Height)
{}

// Gets a value indicating whether this PointF is empty.
bool Point::IsEmpty() const
{
    return X == 0 && Y == 0;
}

// Operators

// Translates a Point by a given Size.
Point Point::operator+(struct Size const &size) const
{
    return Drawing::Point(X + size.Width, Y + size.Height);
}

// Compares two Point objects. The result specifies whether the values of the X and Y properties of the two Point objects are equal.
bool Point::operator==(struct Point const &point) const
{
    return X == point.X && Y == point.Y;
}

// Converts the specified Point structure to a Size structure.
Point::operator struct Size() const
{
    return Drawing::Size(X, Y);
}

// Converts the specified Point structure to a PointF structure.
Point::operator struct PointF() const
{
    return Drawing::PointF(float(X), float(Y));
}

// Compares two Point objects. The result specifies whether the values of the X or Y properties of the two Point objects are unequal.
bool Point::operator!=(Point const &point) const
{
    return X != point.X || Y != point.Y;
}

// Translates a Point by the negative of a given Size.
struct Point Point::operator-(struct Size const &size) const
{
    return Drawing::Point(X - size.Width, Y - size.Height);
}
