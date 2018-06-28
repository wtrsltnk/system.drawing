#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace System
{
namespace Drawing
{

struct Rectangle
{
    // Gets the y-coordinate that is the sum of Y and Height of this Rectangle structure.
    int Bottom;

    // Gets or sets the height of this Rectangle structure.
    int Height;

    // Tests whether the Width or Height property of this Rectangle has a value of zero.
    bool IsEmpty() const;

    // Gets the x-coordinate of the left edge of this Rectangle structure.
    int Left;

    // Gets or sets the coordinates of the upper-left corner of this Rectangle structure.
    struct Point Location() const;

    // Gets the x-coordinate that is the sum of X and Width of this Rectangle structure.
    int Right;

    // Gets or sets the size of this Rectangle.
    struct Size Size() const;

    // Gets the y-coordinate of the top edge of this Rectangle structure.
    int Top;

    // Gets or sets the width of this Rectangle structure.
    int Width;

    // Gets or sets the x-coordinate of the upper-left corner of this Rectangle structure.
    int X;

    // Gets or sets the y-coordinate of the upper-left corner of this Rectangle structure.
    int Y;
};

}   // Drawing
}   // System

#endif // RECTANGLE_H
