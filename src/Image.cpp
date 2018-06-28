#include <system.drawing/system.drawing.image.h>

using namespace System::Drawing;

// Propeties

// Gets attribute flags for the pixel data of this Image.
int Image::Flags() const
{
    return _flags;
}

// Gets the height, in pixels, of this Image.
int Image::Height() const
{
    return _height;
}

// Gets the horizontal resolution, in pixels per inch, of this Image.
float Image::HorizontalResolution() const
{
    return _horizontalResolution;
}

// Gets the width and height of this image.
struct SizeF Image::PhysicalDimension() const {}

// Gets the width and height, in pixels, of this image.
struct Size Image::Size() const
{
    return System::Drawing::Size(_width, _height);
}

// Gets or sets an object that provides additional data about the image.
void *Image::Tag() const
{
    return _tag;
}

// Gets the vertical resolution, in pixels per inch, of this Image.
float Image::VerticalResolution() const
{
    return _verticalResolution;
}

// Gets the width, in pixels, of this Image.
int Image::Width() const
{
    return _width;
}

// Creates an Image from the specified file.
Image *Image::FromFile(std::string const &filename)
{
    return nullptr;
}

// Creates an Image from the specified file using embedded color management information in that file.
Image *Image::FromFile(std::string const &filename, bool useEmbeddedColorManagement)
{
    return nullptr;
}

// Creates a Bitmap from a handle to a GDI bitmap.
Image *Image::FromHbitmap(HBITMAP hbitmap)
{
    return nullptr;
}

// Creates a Bitmap from a handle to a GDI bitmap and a handle to a GDI palette.
Image *Image::FromHbitmap(HBITMAP hbitmap, HPALETTE hpalette)
{
    return nullptr;
}

// Creates an Image from the specified data stream.
Image *Image::FromStream(std::ofstream &stream)
{
    return nullptr;
}

// Creates an Image from the specified data stream, optionally using embedded color management information in that stream.
Image *Image::FromStream(std::ofstream &stream, bool useEmbeddedColorManagement)
{
    return nullptr;
}

// Creates an Image from the specified data stream, optionally using embedded color management information and validating the image data.
Image *Image::FromStream(std::ofstream &stream, bool useEmbeddedColorManagement, bool validateImageData)
{
    return nullptr;
}
