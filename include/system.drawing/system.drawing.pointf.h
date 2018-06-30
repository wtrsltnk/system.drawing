#ifndef POINTF_H
#define POINTF_H

namespace System {
namespace Drawing {

struct PointF
{
    // Initializes a new instance of the PointF class with the specified coordinates.
    PointF(float x, float y);

    // Gets a value indicating whether this PointF is empty.
    bool IsEmpty() const;

    // Gets or sets the x-coordinate of this PointF.
    float X;

    // Gets or sets the y-coordinate of this PointF.
    float Y;

    // Methods

    // Translates a given PointF by the specified Size.
    static struct PointF Add(struct PointF const &point, struct Size const &size);

    // Translates a given PointF by a specified SizeF.
    static struct PointF Add(struct PointF const &point, struct SizeF const &size);

    // Translates a PointF by the negative of a specified size.
    static struct PointF Subtract(struct PointF const &point, struct Size const &size);

    // Translates a PointF by the negative of a specified size.
    static struct PointF Subtract(struct PointF const &point, struct SizeF const &size);

    // Operators

    // Translates a PointF by a given Size.
    struct PointF operator+(struct Size const &size) const;

    // Translates the PointF by the specified SizeF.
    struct PointF operator+(struct SizeF const &size) const;

    // Compares two PointF structures. The result specifies whether the values of the X and Y properties of the two PointF structures are equal.
    bool operator==(struct PointF const &point) const;

    // Determines whether the coordinates of the specified points are not equal.
    bool operator!=(struct PointF const &point) const;

    // Translates a PointF by the negative of a given Size.
    struct PointF operator-(struct Size const &size) const;

    // Translates a PointF by the negative of a specified SizeF.
    struct PointF operator-(struct SizeF const &size) const;
};

} // namespace Drawing
} // namespace System

#endif // POINTF_H
