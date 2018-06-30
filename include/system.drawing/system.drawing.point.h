#ifndef POINT_H
#define POINT_H

namespace System {
namespace Drawing {

struct Point
{
    // Constructors

    // Initializes a new instance of the Point class using coordinates specified by an integer value.
    Point(int dw);

    // Initializes a new instance of the Point class with the specified coordinates.
    Point(int x, int y);

    // Initializes a new instance of the Point class from a Size.
    Point(struct Size const &size);

    // Properties

    // Gets a value indicating whether this Point is empty.
    bool IsEmpty() const;

    // Gets or sets the x-coordinate of this Point.
    float X;

    // Gets or sets the y-coordinate of this Point.
    float Y;

    // Operators

    // Translates a Point by a given Size.
    Point operator+(struct Size const &size) const;

    // Compares two Point objects. The result specifies whether the values of the X and Y properties of the two Point objects are equal.
    bool operator==(struct Point const &point) const;

    // Converts the specified Point structure to a Size structure.
    operator struct Size() const;

    // Converts the specified Point structure to a PointF structure.
    operator struct PointF() const;

    // Compares two Point objects. The result specifies whether the values of the X or Y properties of the two Point objects are unequal.
    bool operator!=(Point const &point2) const;

    // Translates a Point by the negative of a given Size.
    struct Point operator-(struct Size const &size) const;
};

} // namespace Drawing
} // namespace System

#endif // POINT_H
