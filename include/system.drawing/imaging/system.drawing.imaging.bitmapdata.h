#ifndef BITMAPDATA_H
#define BITMAPDATA_H

#include <system.drawing/Imaging/system.drawing.imaging.pixelformat.h>

namespace System {
namespace Drawing {
namespace Imaging {

typedef unsigned char byte;

class BitmapData
{
public: // Constructors
    // Initializes a new instance of the BitmapData class.
    BitmapData();

public: // Properties
    // Gets or sets the pixel height of the Bitmap object. Also sometimes referred to as the number of scan lines.
    int Height;

    // Gets or sets the format of the pixel information in the Bitmap object that returned this BitmapData object.
    Imaging::PixelFormat PixelFormat;

    // Reserved. Do not use.
    int Reserved;

    // Gets or sets the address of the first pixel data in the bitmap. This can also be thought of as the first scan line in the bitmap.
    byte *Scan0;

    // Gets or sets the stride width (also called scan width) of the Bitmap object.
    int Stride;

    // Gets or sets the pixel width of the Bitmap object. This can also be thought of as the number of pixels in one scan line.
    int Width;
};

} // namespace Imaging
} // namespace Drawing
} // namespace System

#endif // BITMAPDATA_H
