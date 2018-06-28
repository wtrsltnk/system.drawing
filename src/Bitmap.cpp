#include <system.drawing/system.drawing.bitmap.h>
#include <system.drawing/system.drawing.color.h>
#include <system.drawing/system.drawing.rectangle.h>

using namespace System::Drawing;

// Creates a copy of the section of this Bitmap defined by Rectangle structure and with a specified PixelFormat enumeration.
Bitmap *Bitmap::Clone(struct Rectangle rect, Imaging::PixelFormat format)
{
    return nullptr;
}

// Creates a copy of the section of this Bitmap defined with a specified PixelFormat enumeration.
Bitmap *Bitmap::Clone(RectangleF rect, Imaging::PixelFormat format)
{
    return nullptr;
}

// Gets the color of the specified pixel in this Bitmap.
struct Color Bitmap::GetPixel(int x, int y) const {}

// Returns a thumbnail for this Image.(Inherited from Image.)
Image *Bitmap::GetThumbnailImage(int thumbWidth, int thumbHeight) const
{
    return nullptr;
}

// Locks a Bitmap into system memory.
Imaging::BitmapData *Bitmap::LockBits(Rectangle &rect, Imaging::ImageLockMode flags, Imaging::PixelFormat format)
{
    return nullptr;
}

// Locks a Bitmap into system memory
Imaging::BitmapData *Bitmap::LockBits(struct Rectangle rect, Imaging::ImageLockMode flags, Imaging::PixelFormat format, Imaging::BitmapData *bitmapData)
{
    return nullptr;
}

// Makes the default transparent color transparent for this Bitmap.
void Bitmap::MakeTransparent() {}

// Makes the specified color transparent for this Bitmap.
void Bitmap::MakeTransparent(struct Color transparentColor) {}

// Sets the color of the specified pixel in this Bitmap.
void Bitmap::SetPixel(int x, int y, struct Color color) {}

// Sets the resolution for this Bitmap.
void Bitmap::SetResolution(float xDpi, float yDpi) {}

// Unlocks this Bitmap from system memory.
void Bitmap::UnlockBits(Imaging::BitmapData *bitmapData) {}
