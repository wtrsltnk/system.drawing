#include "stb_image.h"
#include "stb_image_write.h"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <ios>
#include <iterator>
#include <system.drawing/system.drawing.bitmap.h>
#include <system.drawing/system.drawing.color.h>
#include <system.drawing/system.drawing.rectangle.h>

using namespace System::Drawing;

// Constructors

// Initializes a new instance of the Bitmap class from the specified existing image.
Bitmap::Bitmap(Image *original)
    : _xDpi(300.0f), _yDpi(300.0f)
{}

// Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
Bitmap::Bitmap(Image *original, int width, int height)
    : _xDpi(300.0f), _yDpi(300.0f)
{}

// Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
Bitmap::Bitmap(Image *original, struct Size size)
    : _xDpi(300.0f), _yDpi(300.0f)
{}

// Initializes a new instance of the Bitmap class with the specified size.
Bitmap::Bitmap(int width, int height)
    : _xDpi(300.0f), _yDpi(300.0f)
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
    : _xDpi(300.0f), _yDpi(300.0f)
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
    : _xDpi(300.0f), _yDpi(300.0f)
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
Bitmap::Bitmap(std::istream &stream) : Bitmap(stream, false)
{}

// Initializes a new instance of the Bitmap class from the specified data stream.
Bitmap::Bitmap(std::istream &stream, bool useIcm)
    : _xDpi(300.0f), _yDpi(300.0f)
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
Bitmap::Bitmap(std::string const &filename) : Bitmap(filename, false)
{}

// Initializes a new instance of the Bitmap class from the specified file.
Bitmap::Bitmap(std::string const &filename, bool useIcm)
    : _xDpi(300.0f), _yDpi(300.0f)
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

// Propeties

// Gets attribute flags for the pixel data of this Image.
int Bitmap::Flags() const
{
    return _flags;
}

// Gets the height, in pixels, of this Image.
int Bitmap::Height() const
{
    return _bitmapData.Height;
}

// Gets the horizontal resolution, in pixels per inch, of this Image.
float Bitmap::HorizontalResolution() const
{
    return _xDpi;
}

// Gets or sets the color palette used for this Image.
Imaging::ColorPalette const *Bitmap::Palette() const
{
    return nullptr;
}

// Gets the width and height of this image.
SizeF Bitmap::PhysicalDimension() const
{
    return Drawing::SizeF(float(Width()), float(Height()));
}

// Gets the pixel format for this Image.
Imaging::PixelFormat Bitmap::PixelFormat() const
{
    return _bitmapData.PixelFormat;
}

// Gets the file format of this Image.
Imaging::ImageFormat *Bitmap::RawFormat()
{
    return nullptr;
}

// Gets the width and height, in pixels, of this image.
struct Size Bitmap::Size() const
{
    return Drawing::Size(Width(), Height());
}

// Gets the vertical resolution, in pixels per inch, of this Image.
float Bitmap::VerticalResolution() const
{
    return _yDpi;
}

// Gets the width, in pixels, of this Image.
int Bitmap::Width() const
{
    return _bitmapData.Width;
}

// Methods

// Creates an exact copy of this Image.
Image *Bitmap::Clone() const
{
    return nullptr;
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

RectangleF Bitmap::GetBounds(GraphicsUnit &pageUnit) const
{
    return RectangleF(0.0f, 0.0f, float(Width()), float(Height()));
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
            Color &color = *((struct Color *)pixelData);
            pixel.R = color.R;
            pixel.G = color.G;
            pixel.B = color.B;
            break;
        }
    }

    return pixel;
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

// Rotates, flips, or rotates and flips the Image.
void Bitmap::RotateFlip(RotateFlipType rotateFlipType) {}

void stbi_local_write_func(void *context, void *data, int size)
{
    auto stream = (std::ostream *)context;
    stream->write((const char *)data, size);
}

// Saves this image to the specified stream in the specified format.
void Bitmap::Save(std::ostream &stream, Imaging::ImageFormat const &format)
{
    int bitsPerPixel = ((int)(_bitmapData.PixelFormat) & 0xff00) >> 8;
    int bytesPerPixel = (bitsPerPixel + 7) / 8;

    if (format.Guid() == Imaging::ImageFormat::Bmp().Guid())
    {
        stbi_write_bmp_to_func(stbi_local_write_func, &stream, _bitmapData.Width, _bitmapData.Height, bytesPerPixel, (const void *)_bitmapData.Scan0);
    }

    if (format.Guid() == Imaging::ImageFormat::Png().Guid())
    {
        stbi_write_png_to_func(stbi_local_write_func, &stream, _bitmapData.Width, _bitmapData.Height, bytesPerPixel, (const void *)_bitmapData.Scan0, _bitmapData.Stride - _bitmapData.Width);
    }

    if (format.Guid() == Imaging::ImageFormat::Jpeg().Guid())
    {
        stbi_write_jpg_to_func(stbi_local_write_func, &stream, _bitmapData.Width, _bitmapData.Height, bytesPerPixel, (const void *)_bitmapData.Scan0, 95);
    }

    if (format.Guid() == Imaging::ImageFormat::Tga().Guid())
    {
        stbi_write_tga_to_func(stbi_local_write_func, &stream, _bitmapData.Width, _bitmapData.Height, bytesPerPixel, (const void *)_bitmapData.Scan0);
    }
}

// Saves this Image to the specified file or stream.
void Bitmap::Save(std::string const &filename)
{
    auto found = filename.find_last_of('.');
    if (found == std::string::npos)
    {
        Save(filename, Imaging::ImageFormat::Bmp());
    }

    auto ext = filename.substr(found);
    if (ext == ".bmp")
    {
        Save(filename, Imaging::ImageFormat::Bmp());
    }
    if (ext == ".png")
    {
        Save(filename, Imaging::ImageFormat::Png());
    }
    if (ext == ".jpg"  || ext == ".jpeg")
    {
        Save(filename, Imaging::ImageFormat::Jpeg());
    }
    if (ext == ".tga")
    {
        Save(filename, Imaging::ImageFormat::Tga());
    }
}

// Saves this Image to the specified file in the specified format.
void Bitmap::Save(std::string const &filename, Imaging::ImageFormat const &format)
{
    auto stream = std::ofstream();
    stream.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

    stream.open(filename, std::ios::binary);

    Save(stream, format);

    stream.close();
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
            Color &pixel = *((struct Color *)pixelData);
            pixel.R = color.R;
            pixel.G = color.G;
            pixel.B = color.B;
            break;
        }
    }
}

// Sets the resolution for this Bitmap.
void Bitmap::SetResolution(float xDpi, float yDpi)
{
    _xDpi = xDpi;
    _yDpi = yDpi;
}

// Unlocks this Bitmap from system memory.
void Bitmap::UnlockBits(Imaging::BitmapData *bitmapData) {}
