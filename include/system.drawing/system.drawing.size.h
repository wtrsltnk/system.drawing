#ifndef SIZE_H
#define SIZE_H

#include <system.drawing/system.drawing.point.h>
#include <system.drawing/system.drawing.sizeF.h>

namespace System {
namespace Drawing {

struct Size
{
    // Initializes a new instance of the Size structure from the specified dimensions.
    Size(int width, int height);

    // Initializes a new instance of the Size structure from the specified Point structure.
    Size(struct Point point);

    // Gets or sets the vertical component of this Size structure.
    int Height;

    // Tests whether this Size structure has width and height of 0.
    bool IsEmpty() const;

    // Gets or sets the horizontal component of this Size structure.
    int Width;

    // Operators

    // Adds the width and height of one Size structure to the width and height of another Size structure.
    struct Size operator+(struct Size const &size) const;

    // Tests whether two Size structures are equal.
    bool operator==(struct Size const &size) const;

    // Converts the specified Size structure to a Point structure.
    operator Point() const;

    // Converts the specified Size structure to a SizeF structure.
    operator SizeF() const;

    // Tests whether two Size structures are different.
    bool operator!=(struct Size const &size) const;

    // Subtracts the width and height of one Size structure from the width and height of another Size structure.
    struct Size operator-(struct Size const &size) const;
};

} // namespace Drawing
} // namespace System

#endif // SIZE_H
