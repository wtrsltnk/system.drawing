#ifndef IMAGEFORMAT_H
#define IMAGEFORMAT_H

#include <string>

namespace System {
namespace Drawing {
namespace Imaging {

class ImageFormat
{
public: // Constructors
    ImageFormat(std::string &guid);

public: // Properties
    // Gets the bitmap (BMP) image format.
    static ImageFormat *Bmp();

    // Gets the enhanced metafile (EMF) image format.
    static ImageFormat *Emf();

    // Gets the Exchangeable Image File (Exif) format.
    static ImageFormat *Exif();

    // Gets the Graphics Interchange Format (GIF) image format.
    static ImageFormat *Gif();

    // Gets a Guid structure that represents this ImageFormat object.
    std::string	const &Guid() const;

    // Gets the Windows icon image format.
    static ImageFormat *Icon();

    // Gets the Joint Photographic Experts Group (JPEG) image format.
    static ImageFormat *Jpeg();

    // Gets the format of a bitmap in memory.
    static ImageFormat *MemoryBmp();

    // Gets the W3C Portable Network Graphics (PNG) image format.
    static ImageFormat *Png();

    // Gets the Tagged Image File Format (TIFF) image format.
    static ImageFormat *Tiff();

    // Gets the Windows metafile (WMF) image format.
    static ImageFormat *Wmf();

};

} // namespace Imaging
} // namespace Drawing
} // namespace System

#endif // IMAGEFORMAT_H
