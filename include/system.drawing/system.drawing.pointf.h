#ifndef POINTF_H
#define POINTF_H

namespace System {
namespace Drawing {

struct PointF
{
    // Gets a value indicating whether this PointF is empty.
    bool IsEmpty() const;

    // Gets or sets the x-coordinate of this PointF.
    float X;

    // Gets or sets the y-coordinate of this PointF.
    float Y;
};

} // namespace Drawing
} // namespace System

#endif // POINTF_H
