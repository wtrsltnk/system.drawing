#include <system.drawing/imaging/system.drawing.imaging.imageformat.h>

using namespace System::Drawing::Imaging;

// Constructors

ImageFormat::ImageFormat(std::string const &guid)
    : _guid(guid)
{}

// Properties
// Gets the bitmap (BMP) image format.
ImageFormat const &ImageFormat::Bmp()
{
    static ImageFormat format("3162a013-4d8d-47a8-b0d3-3a4e969187a2");

    return format;
}

// Gets the enhanced metafile (EMF) image format.
ImageFormat const &ImageFormat::Emf()
{
    static ImageFormat format("ab2b7e28-8bbb-4083-a0f1-3d5300b4d736");

    return format;
}

// Gets the Exchangeable Image File (Exif) format.
ImageFormat const &ImageFormat::Exif()
{
    static ImageFormat format("5f57bbca-12ed-4c2b-b3a9-be9cc8689cda");

    return format;
}

// Gets the Graphics Interchange Format (GIF) image format.
ImageFormat const &ImageFormat::Gif()
{
    static ImageFormat format("15ffe43f-60e5-46be-9e66-f03c61b4c4cc");

    return format;
}

// Gets a Guid structure that represents this ImageFormat object.
std::string const &ImageFormat::Guid() const
{
    return _guid;
}

// Gets the Windows icon image format.
ImageFormat const &Icon()
{
    static ImageFormat format("e9f72fb4-e87a-49c6-9428-0845c0540859");

    return format;
}

// Gets the Joint Photographic Experts Group (JPEG) image format.
ImageFormat const &ImageFormat::Jpeg()
{
    static ImageFormat format("df15a13c-1351-473f-a735-9e981485718d");

    return format;
}

// Gets the format of a bitmap in memory.
ImageFormat const &ImageFormat::MemoryBmp()
{
    static ImageFormat format("cf7623a3-0d1a-466c-8b5d-9983b19b4993");

    return format;
}

// Gets the W3C Portable Network Graphics (PNG) image format.
ImageFormat const &ImageFormat::Png()
{
    static ImageFormat format("e64f5bb4-f900-42bf-8101-b92a603e1528");

    return format;
}

// Gets the Truevision Graphics Adapter (Tga) image format.
ImageFormat const &ImageFormat::Tga()
{
    static ImageFormat format("804afee3-8390-4404-83ca-dfb746099461");

    return format;
}

// Gets the Tagged Image File Format (TIFF) image format.
ImageFormat const &ImageFormat::Tiff()
{
    static ImageFormat format("eeb22bd8-5973-4931-9c45-788bdf0d4baa");

    return format;
}

// Gets the Windows metafile (WMF) image format.
ImageFormat const &ImageFormat::Wmf()
{
    static ImageFormat format("d77f3aaa-f0ca-4343-b0fd-f83dfbf1fa95");

    return format;
}
