#ifndef PIXELFORMAT_H
#define PIXELFORMAT_H

namespace System {
namespace Drawing {
namespace Imaging {

enum class PixelFormat
{
    // The pixel data contains alpha values that are not premultiplied.
    Alpha,

    // The default pixel format of 32 bits per pixel. The format specifies 24-bit color depth and an 8-bit alpha channel.
    Canonical,

    // No pixel format is specified.
    DontCare,

    // Reserved.
    Extended,

    // The pixel format is 16 bits per pixel. The color information specifies 32,768 shades of color, of which 5 bits are red, 5 bits are green, 5 bits are blue, and 1 bit is alpha.
    Format16bppArgb1555,

    // The pixel format is 16 bits per pixel. The color information specifies 65536 shades of gray.
    Format16bppGrayScale,

    // Specifies that the format is 16 bits per pixel; 5 bits each are used for the red, green, and blue components. The remaining bit is not used.
    Format16bppRgb555,

    // Specifies that the format is 16 bits per pixel; 5 bits are used for the red component, 6 bits are used for the green component, and 5 bits are used for the blue component.
    Format16bppRgb565,

    // Specifies that the pixel format is 1 bit per pixel and that it uses indexed color. The color table therefore has two colors in it.
    Format1bppIndexed,

    // Specifies that the format is 24 bits per pixel; 8 bits each are used for the red, green, and blue components.
    Format24bppRgb,

    // Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components.
    Format32bppArgb,

    // Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied, according to the alpha component.
    Format32bppPArgb,

    // Specifies that the format is 32 bits per pixel; 8 bits each are used for the red, green, and blue components. The remaining 8 bits are not used.
    Format32bppRgb,

    // Specifies that the format is 48 bits per pixel; 16 bits each are used for the red, green, and blue components.
    Format48bppRgb,

    // Specifies that the format is 4 bits per pixel, indexed.
    Format4bppIndexed,

    // Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components.
    Format64bppArgb,

    // Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component.
    Format64bppPArgb,

    // Specifies that the format is 8 bits per pixel, indexed. The color table therefore has 256 colors in it.
    Format8bppIndexed,

    // The pixel data contains GDI colors.
    Gdi,

    // The pixel data contains color-indexed values, which means the values are an index to colors in the system color table, as opposed to individual color values.
    Indexed,

    // The maximum value for this enumeration.
    Max,

    // The pixel format contains premultiplied alpha values.
    PAlpha,

    // The pixel format is undefined.
    Undefined,

};

} // namespace Imaging
} // namespace Drawing
} // namespace System

#endif // PIXELFORMAT_H
