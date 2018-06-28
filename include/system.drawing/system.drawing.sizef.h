#ifndef SIZEF_H
#define SIZEF_H

namespace System {
namespace Drawing {

struct SizeF
{
    // Gets or sets the vertical component of this SizeF structure.
    float Height;

    // Tests whether this SizeF structure has width and height of 0.
    bool IsEmpty() const;

    // Gets or sets the horizontal component of this SizeF structure.
    float Width;
};

} // namespace Drawing
} // namespace System

#endif // SIZEF_H
