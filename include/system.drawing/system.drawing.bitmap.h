#ifndef BITMAP_H
#define BITMAP_H

#include <system.drawing/imaging/system.drawing.imaging.bitmapdata.h>
#include <system.drawing/imaging/system.drawing.imaging.imageformat.h>
#include <system.drawing/imaging/system.drawing.imaging.imagelockmode.h>
#include <system.drawing/imaging/system.drawing.imaging.pixelformat.h>
#include <system.drawing/system.drawing.image.h>

namespace System {
namespace Drawing {

class Bitmap : public Image
{
    Imaging::BitmapData _bitmapData;

public: // Constructors
        // Initializes a new instance of the Bitmap class from the specified existing image.
    Bitmap(Image *original);

    // Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
    Bitmap(Image *original, int width, int height);

    // Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
    Bitmap(Image *original, struct Size size);

    // Initializes a new instance of the Bitmap class with the specified size.
    Bitmap(int width, int height);

    // Initializes a new instance of the Bitmap class with the specified size and with the resolution of the specified Graphics object.
    // System_CAPS_pubmethod Bitmap(Int32, Int32, Graphics)

    // Initializes a new instance of the Bitmap class with the specified size, pixel format, and pixel data.
    Bitmap(int width, int height, int stride, Imaging::PixelFormat format, byte *scan0);

    // Initializes a new instance of the Bitmap class with the specified size and format.
    Bitmap(int width, int height, Imaging::PixelFormat format);

    // Initializes a new instance of the Bitmap class from the specified data stream.
    Bitmap(std::istream &stream);

    // Initializes a new instance of the Bitmap class from the specified data stream.
    Bitmap(std::istream &stream, bool useIcm);

    // Initializes a new instance of the Bitmap class from the specified file.
    Bitmap(std::string const &filename);

    // Initializes a new instance of the Bitmap class from the specified file.
    Bitmap(std::string const &filename, bool useIcm);

    // Initializes a new instance of the Bitmap class from a specified resource.
    // System_CAPS_pubmethod	Bitmap(Type, String)

    virtual ~Bitmap();

public: // Methods
    // Creates a copy of the section of this Bitmap defined by Rectangle structure and with a specified PixelFormat enumeration.
    Bitmap *Clone(struct Rectangle rect, Imaging::PixelFormat format);

    // Creates a copy of the section of this Bitmap defined with a specified PixelFormat enumeration.
    Bitmap *Clone(struct RectangleF rect, Imaging::PixelFormat format);

    // Creates a Bitmap from a Windows handle to an icon.
    // System_CAPS_pubmethodSystem_CAPS_static;FromHicon(IntPtr);

    // Creates a Bitmap from the specified Windows resource.
    // System_CAPS_pubmethodSystem_CAPS_static;FromResource(IntPtr, String);

    // Creates a GDI bitmap object from this Bitmap.
    // GetHbitmap();

    // Creates a GDI bitmap object from this Bitmap.
    // GetHbitmap(Color);

    // Returns the handle to an icon.
    // GetHicon();

    // Gets the color of the specified pixel in this Bitmap.
    struct Color GetPixel(int x, int y) const;

    // Locks a Bitmap into system memory.
    Imaging::BitmapData *LockBits(Rectangle &rect, Imaging::ImageLockMode flags, Imaging::PixelFormat format);

    // Locks a Bitmap into system memory
    Imaging::BitmapData *LockBits(Rectangle rect, Imaging::ImageLockMode flags, Imaging::PixelFormat format, Imaging::BitmapData *bitmapData);

    // Makes the default transparent color transparent for this Bitmap.
    void MakeTransparent();

    // Makes the specified color transparent for this Bitmap.
    void MakeTransparent(struct Color transparentColor);

    // Gets the pixel format for this Image.
    virtual Imaging::PixelFormat PixelFormat() const;

    // Sets the color of the specified pixel in this Bitmap.
    void SetPixel(int x, int y, Color color);

    // Sets the resolution for this Bitmap.
    void SetResolution(float xDpi, float yDpi);

    // Unlocks this Bitmap from system memory.
    void UnlockBits(Imaging::BitmapData *bitmapData);
};

} // namespace Drawing
} // namespace System

#endif // BITMAP_H
