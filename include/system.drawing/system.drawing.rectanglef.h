#ifndef RECTANGLEF_H
#define RECTANGLEF_H

#include <system.drawing/system.drawing.pointf.h>
#include <system.drawing/system.drawing.sizef.h>

namespace System
{
namespace Drawing
{

struct RectangleF
{
    // Gets the y-coordinate that is the sum of Y and Height of this RectangleF structure.
    float Bottom;

    // Gets or sets the height of this RectangleF structure.
    float Height;

    // Tests whether the Width or Height property of this RectangleF has a value of zero.
    bool IsEmpty() const;

    // Gets the x-coordinate of the left edge of this RectangleF structure.
    float Left;

    // Gets or sets the coordinates of the upper-left corner of this RectangleF structure.
    PointF Location() const;

    // Gets the x-coordinate that is the sum of X and Width of this RectangleF structure.
    float Right;

    // Gets or sets the size of this RectangleF.
    SizeF Size() const;

    // Gets the y-coordinate of the top edge of this RectangleF structure.
    float Top;

    // Gets or sets the width of this RectangleF structure.
    float Width;

    // Gets or sets the x-coordinate of the upper-left corner of this RectangleF structure.
    float X;

    // Gets or sets the y-coordinate of the upper-left corner of this RectangleF structure.
    float Y;
};

}   // Drawing
}   // System

#endif // RECTANGLEF_H
