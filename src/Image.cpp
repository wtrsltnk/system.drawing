#include <ios>
#include <system.drawing/system.drawing.bitmap.h>
#include <system.drawing/system.drawing.image.h>

using namespace System::Drawing;

// Propeties

// Gets or sets an object that provides additional data about the image.
void *Image::Tag() const
{
    return _tag;
}

// Creates an Image from the specified file.
Image *Image::FromFile(std::string const &filename)
{
    return Image::FromFile(filename, false);
}

// Creates an Image from the specified file using embedded color management information in that file.
Image *Image::FromFile(std::string const &filename, bool useEmbeddedColorManagement)
{
    try
    {
        return new Bitmap(filename, useEmbeddedColorManagement);
    } catch (std::ios_base::failure &ex)
    {
        return nullptr;
    }
}

// Creates an Image from the specified data stream.
Image *Image::FromStream(std::istream &stream)
{
    return Image::FromStream(stream, false, false);
}

// Creates an Image from the specified data stream, optionally using embedded color management information in that stream.
Image *Image::FromStream(std::istream &stream, bool useEmbeddedColorManagement)
{
    return Image::FromStream(stream, useEmbeddedColorManagement, false);
}

// Creates an Image from the specified data stream, optionally using embedded color management information and validating the image data.
Image *Image::FromStream(std::istream &stream, bool useEmbeddedColorManagement, bool validateImageData)
{
    try
    {
        return new Bitmap(stream);
    } catch (std::ios_base::failure &ex)
    {
        return nullptr;
    }
}
