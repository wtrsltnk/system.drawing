#ifndef SIZEF_H
#define SIZEF_H

namespace System {
namespace Drawing {

struct SizeF
{
    // Initializes a new instance of the SizeF structure from the specified PointF structure.
    SizeF(struct PointF const &point);

    // Initializes a new instance of the SizeF structure from the specified dimensions.
    SizeF(float w, float h);

    // Initializes a new instance of the SizeF structure from the specified existing SizeF structure.
    SizeF(struct SizeF const &size);

    // Gets or sets the vertical component of this SizeF structure.
    float Height;

    // Tests whether this SizeF structure has width and height of 0.
    bool IsEmpty() const;

    // Gets or sets the horizontal component of this SizeF structure.
    float Width;

    // Operators

    // Adds the width and height of one SizeF structure to the width and height of another SizeF structure.
    SizeF operator+(struct SizeF const &size) const;

    // Tests whether two SizeF structures are equal.
    bool operator==(struct SizeF const &size) const;

    // Converts the specified SizeF structure to a PointF structure.
    operator struct PointF() const;

    // Tests whether two SizeF structures are different.
    bool operator!=(struct SizeF const &size);

    // Subtracts the width and height of one SizeF structure from the width and height of another SizeF structure.
    struct SizeF operator-(struct SizeF const &size);
};

} // namespace Drawing
} // namespace System

#endif // SIZEF_H
