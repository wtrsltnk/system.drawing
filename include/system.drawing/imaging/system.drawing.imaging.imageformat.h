#ifndef IMAGEFORMAT_H
#define IMAGEFORMAT_H

#include <string>

namespace System {
namespace Drawing {
namespace Imaging {

class ImageFormat
{
    std::string _guid;

public: // Constructors
    ImageFormat(std::string const &guid);

public: // Properties
    // Gets the bitmap (BMP) image format.
    static ImageFormat const &Bmp();

    // Gets the enhanced metafile (EMF) image format.
    static ImageFormat const &Emf();

    // Gets the Exchangeable Image File (Exif) format.
    static ImageFormat const &Exif();

    // Gets the Graphics Interchange Format (GIF) image format.
    static ImageFormat const &Gif();

    // Gets a Guid structure that represents this ImageFormat object.
    std::string const &Guid() const;

    // Gets the Windows icon image format.
    static ImageFormat const &Icon();

    // Gets the Joint Photographic Experts Group (JPEG) image format.
    static ImageFormat const &Jpeg();

    // Gets the format of a bitmap in memory.
    static ImageFormat const &MemoryBmp();

    // Gets the W3C Portable Network Graphics (PNG) image format.
    static ImageFormat const &Png();

    // Gets the Truevision Graphics Adapter (Tga) image format.
    static ImageFormat const &Tga();

    // Gets the Tagged Image File Format (TIFF) image format.
    static ImageFormat const &Tiff();

    // Gets the Windows metafile (WMF) image format.
    static ImageFormat const &Wmf();
};

} // namespace Imaging
} // namespace Drawing
} // namespace System

#endif // IMAGEFORMAT_H
