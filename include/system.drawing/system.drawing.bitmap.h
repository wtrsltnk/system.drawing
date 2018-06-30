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
    int _flags;
    float _xDpi, _yDpi;

public: // Constructors
        // Initializes a new instance of the Bitmap class from the specified existing image.
    Bitmap(Bitmap *original);

    // Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
    Bitmap(Bitmap *original, int width, int height);

    // Initializes a new instance of the Bitmap class from the specified existing image, scaled to the specified size.
    Bitmap(Bitmap *original, struct Size size);

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

public: // Propeties
    // Gets attribute flags for the pixel data of this Image.
    virtual int Flags() const;

    // Gets an array of GUIDs that represent the dimensions of frames within this Image.
    // System_CAPS_pubproperty	FrameDimensionsList

    // Gets the height, in pixels, of this Image.
    virtual int Height() const;

    // Gets the horizontal resolution, in pixels per inch, of this Image.
    virtual float HorizontalResolution() const;

    // Gets or sets the color palette used for this Image.
    virtual Imaging::ColorPalette const *Palette() const;

    // Gets the width and height of this image.
    virtual SizeF PhysicalDimension() const;

    // Gets the pixel format for this Image.
    virtual Imaging::PixelFormat PixelFormat() const;

    // Gets IDs of the property items stored in this Image.
    // System_CAPS_pubproperty	PropertyIdList

    // Gets all the property items (pieces of metadata) stored in this Image.
    // System_CAPS_pubproperty	PropertyItems

    // Gets the file format of this Image.
    virtual Imaging::ImageFormat *RawFormat();

    // Gets the width and height, in pixels, of this image.
    virtual struct Size Size() const;

    // Gets the vertical resolution, in pixels per inch, of this Image.
    virtual float VerticalResolution() const;

    // Gets the width, in pixels, of this Image.
    virtual int Width() const;

public: // Methods
    // Creates an exact copy of this Image.
    virtual Image *Clone() const;

    // Creates a copy of the section of this Bitmap defined by Rectangle structure and with a specified PixelFormat enumeration.
    Bitmap *Clone(struct Rectangle rect, Imaging::PixelFormat format);

    // Creates a copy of the section of this Bitmap defined with a specified PixelFormat enumeration.
    Bitmap *Clone(struct RectangleF rect, Imaging::PixelFormat format);

    // Creates a Bitmap from a Windows handle to an icon.
    // System_CAPS_pubmethodSystem_CAPS_static;FromHicon(IntPtr);

    // Creates a Bitmap from the specified Windows resource.
    // System_CAPS_pubmethodSystem_CAPS_static;FromResource(IntPtr, String);

    // Gets the bounds of the image in the specified unit.
    virtual RectangleF GetBounds(GraphicsUnit &pageUnit) const;

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

    // Rotates, flips, or rotates and flips the Image.
    virtual void RotateFlip(RotateFlipType rotateFlipType);

    // Saves this image to the specified stream in the specified format.
    virtual void Save(std::ostream &stream, Imaging::ImageFormat const &format);

    // Saves this Image to the specified file or stream.
    virtual void Save(std::string const &filename);

    // Saves this Image to the specified file in the specified format.
    virtual void Save(std::string const &filename, Imaging::ImageFormat const &format);

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
