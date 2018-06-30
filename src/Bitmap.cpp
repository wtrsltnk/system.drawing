#include "stb_image.h"
#include <algorithm>
#include <cstring>
#include <ios>
#include <iterator>
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
    _bitmapData.Scan0 = new byte[height * stride];
    std::memset(_bitmapData.Scan0, 0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class with the specified size and with the resolution of the specified Graphics object.
// System_CAPS_pubmethod Bitmap(Int32, Int32, Graphics)

// Initializes a new instance of the Bitmap class with the specified size, pixel format, and pixel data.
Bitmap::Bitmap(int width, int height, int stride, Imaging::PixelFormat format, byte *scan0)
{
    _bitmapData.Height = height;
    _bitmapData.PixelFormat = format;
    _bitmapData.Scan0 = new byte[height * stride];
    std::memcpy(_bitmapData.Scan0, scan0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class with the specified size and format.
Bitmap::Bitmap(int width, int height, Imaging::PixelFormat format)
{
    int bitsPerPixel = ((int)format & 0xff00) >> 8;
    int bytesPerPixel = (bitsPerPixel + 7) / 8;
    int stride = 4 * ((width * bytesPerPixel + 3) / 4);

    _bitmapData.Height = height;
    _bitmapData.PixelFormat = format;
    _bitmapData.Scan0 = new byte[height * stride];
    std::memset(_bitmapData.Scan0, 0, height * stride);
    _bitmapData.Stride = stride;
    _bitmapData.Width = width;
}

// Initializes a new instance of the Bitmap class from the specified data stream.
Bitmap::Bitmap(std::istream &stream) : Bitmap(stream, false) {}

// Initializes a new instance of the Bitmap class from the specified data stream.
Bitmap::Bitmap(std::istream &stream, bool useIcm)
{
    std::vector<stbi_uc> fileData;

    fileData.insert(fileData.begin(), std::istream_iterator<stbi_uc>(stream), std::istream_iterator<stbi_uc>());

    int x, y, channels;
    auto data = stbi_load_from_memory(fileData.data(), fileData.size(), &x, &y, &channels, 4);

    if (data == nullptr)
    {
        throw std::ios_base::failure("unable to load bitmap file");
    }

    _bitmapData.Height = y;
    _bitmapData.PixelFormat = Imaging::PixelFormat::Format32bppArgb;
    _bitmapData.Scan0 = data;
    _bitmapData.Stride = x;
    _bitmapData.Width = x;
}

// Initializes a new instance of the Bitmap class from the specified file.
Bitmap::Bitmap(std::string const &filename) : Bitmap(filename, false) {}

// Initializes a new instance of the Bitmap class from the specified file.
Bitmap::Bitmap(std::string const &filename, bool useIcm)
{
    int x, y, channels;
    auto data = stbi_load(filename.c_str(), &x, &y, &channels, 4);

    if (data == nullptr)
    {
        throw std::ios_base::failure("unable to load bitmap file");
    }

    _bitmapData.Height = y;
    _bitmapData.PixelFormat = Imaging::PixelFormat::Format32bppArgb;
    _bitmapData.Scan0 = data;
    _bitmapData.Stride = x;
    _bitmapData.Width = x;
}

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
struct Color Bitmap::GetPixel(int x, int y) const
{
    if (x < 0 || x >= _bitmapData.Width)
    {
        throw std::invalid_argument("x");
    }

    if (y < 0 || y >= _bitmapData.Height)
    {
        throw std::invalid_argument("y");
    }

    auto format = PixelFormat();

    auto row = _bitmapData.Scan0 + (_bitmapData.Stride * y);
    int bitsPerPixel = ((int)format & 0xff00) >> 8;
    int bytesPerPixel = (bitsPerPixel + 7) / 8;
    auto pixelData = row + (bytesPerPixel * x);
    struct Color pixel;
    switch (format)
    {
    case Imaging::PixelFormat::Format24bppRgb:
    case Imaging::PixelFormat::Format32bppRgb:
        pixel.A = 255;
    case Imaging::PixelFormat::Format32bppArgb:
    case Imaging::PixelFormat::Format32bppPArgb:
    {
        Color &color = *((struct Color*)pixelData);
        pixel.R = color.R;
        pixel.G = color.G;
        pixel.B = color.B;
        break;
    }
    }
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

Imaging::PixelFormat Bitmap::PixelFormat() const
{
    return _bitmapData.PixelFormat;
}

// Sets the color of the specified pixel in this Bitmap.
void Bitmap::SetPixel(int x, int y, struct Color color)
{
    if (x < 0 || x >= _bitmapData.Width)
    {
        throw std::invalid_argument("x");
    }

    if (y < 0 || y >= _bitmapData.Height)
    {
        throw std::invalid_argument("y");
    }

    auto format = PixelFormat();

    auto row = _bitmapData.Scan0 + (_bitmapData.Stride * y);
    int bitsPerPixel = ((int)format & 0xff00) >> 8;
    int bytesPerPixel = (bitsPerPixel + 7) / 8;
    auto pixelData = row + (bytesPerPixel * x);
    switch (format)
    {
    case Imaging::PixelFormat::Format24bppRgb:
    case Imaging::PixelFormat::Format32bppRgb:
        color.A = 255;
    case Imaging::PixelFormat::Format32bppArgb:
    case Imaging::PixelFormat::Format32bppPArgb:
    {
        Color &pixel = *((struct Color*)pixelData);
        pixel.R = color.R;
        pixel.G = color.G;
        pixel.B = color.B;
        break;
    }
    }
}

// Sets the resolution for this Bitmap.
void Bitmap::SetResolution(float xDpi, float yDpi) {}

// Unlocks this Bitmap from system memory.
void Bitmap::UnlockBits(Imaging::BitmapData *bitmapData) {}
