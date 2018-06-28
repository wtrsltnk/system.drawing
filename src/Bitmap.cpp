#include <cstring>
#include <system.drawing/system.drawing.bitmap.h>
#include <system.drawing/system.drawing.color.h>
#include <system.drawing/system.drawing.rectangle.h>

using namespace System::Drawing;

// Initializes a new instance of the Bitmap class from the specified existing image.
Bitmap::Bitmap(Image *original) {}

// Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
Bitmap::Bitmap(Image *original, int width, int height) {}

// Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
Bitmap::Bitmap(Image *original, struct Size size) {}

// Initializes a new instance of the Bitmap class with the specified size.
Bitmap::Bitmap(int width, int height)
{
    auto stride = width * 4;
    _bitmapData.Height = height;
    _bitmapData.PixelFormat = Imaging::PixelFormat::Canonical;
    _bitmapData.Scan0 = new Imaging::byte[height * stride];
    std::memset(_bitmapData.Scan0, 0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class with the specified size and with the resolution of the specified Graphics object.
// System_CAPS_pubmethod Bitmap(Int32, Int32, Graphics)

// Initializes a new instance of the Bitmap class with the specified size, pixel format, and pixel data.
Bitmap::Bitmap(int width, int height, int stride, Imaging::PixelFormat format, Imaging::byte *scan0)
{
    _bitmapData.Height = height;
    _bitmapData.PixelFormat = format;
    _bitmapData.Scan0 = new Imaging::byte[height * stride];
    std::memcpy(_bitmapData.Scan0, scan0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class with the specified size and format.
Bitmap::Bitmap(int width, int height, Imaging::PixelFormat format)
{
    auto stride = width * 4;
    _bitmapData.Height = height;
    _bitmapData.PixelFormat = format;
    _bitmapData.Scan0 = new Imaging::byte[height * stride];
    std::memset(_bitmapData.Scan0, 0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class from the specified data stream.
Bitmap::Bitmap(std::ostream &stream) {}

// Initializes a new instance of the Bitmap class from the specified data stream.
Bitmap::Bitmap(std::ostream &stream, bool useIcm) {}

// Initializes a new instance of the Bitmap class from the specified file.
Bitmap::Bitmap(std::string const &filename) {}

// Initializes a new instance of the Bitmap class from the specified file.
Bitmap::Bitmap(std::string const &filename, bool useIcm) {}

Bitmap::~Bitmap()
{
    delete[] _bitmapData.Scan0;
}

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
