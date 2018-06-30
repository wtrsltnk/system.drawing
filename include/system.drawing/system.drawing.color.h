#ifndef COLOR_H
#define COLOR_H

#include <string>

namespace System {
namespace Drawing {

typedef unsigned char byte;

struct Color
{
    // Gets the alpha component value of this Color structure.
    byte A;

    // Gets the blue component value of this Color structure.
    byte B;

    // Gets the green component value of this Color structure.
    byte G;

    // Specifies whether this Color structure is uninitialized.
    bool IsEmpty;

    // Gets a value indicating whether this Color structure is a predefined color. Predefined colors are represented by the elements of the KnownColor enumeration.
    bool IsKnownColor;

    // Gets a value indicating whether this Color structure is a named color or a member of the KnownColor enumeration.
    bool IsNamedColor;

    // Gets a value indicating whether this Color structure is a system color. A system color is a color that is used in a Windows display element. System colors are represented by elements of the KnownColor enumeration.
    bool IsSystemColor;

    // Gets the name of this Color.
    std::string Name;

    // Gets the red component value of this Color structure.
    byte R;

};

} // namespace Drawing
} // namespace System

#endif // COLOR_H
