#ifndef SIZE_H
#define SIZE_H

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
};

} // namespace Drawing
} // namespace System

#endif // SIZE_H
