#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <system.drawing/Imaging/system.drawing.imaging.colorpalette.h>
#include <system.drawing/Imaging/system.drawing.imaging.imageformat.h>
#include <system.drawing/Imaging/system.drawing.imaging.pixelformat.h>
#include <system.drawing/system.drawing.graphicsunit.h>
#include <system.drawing/system.drawing.rectanglef.h>
#include <system.drawing/system.drawing.rotatefliptype.h>
#include <system.drawing/system.drawing.size.h>
#include <system.drawing/system.drawing.sizef.h>

namespace System {
namespace Drawing {

class Image
{
protected:
    void *_tag;

public: // Propeties
    // Gets attribute flags for the pixel data of this Image.
    virtual int Flags() const = 0;

    // Gets an array of GUIDs that represent the dimensions of frames within this Image.
    // System_CAPS_pubproperty	FrameDimensionsList

    // Gets the height, in pixels, of this Image.
    virtual int Height() const = 0;

    // Gets the horizontal resolution, in pixels per inch, of this Image.
    virtual float HorizontalResolution() const = 0;

    // Gets or sets the color palette used for this Image.
    virtual Imaging::ColorPalette const *Palette() const = 0;

    // Gets the width and height of this image.
    virtual SizeF PhysicalDimension() const = 0;

    // Gets the pixel format for this Image.
    virtual Imaging::PixelFormat PixelFormat() const = 0;

    // Gets IDs of the property items stored in this Image.
    // System_CAPS_pubproperty	PropertyIdList

    // Gets all the property items (pieces of metadata) stored in this Image.
    // System_CAPS_pubproperty	PropertyItems

    // Gets the file format of this Image.
    virtual Imaging::ImageFormat *RawFormat() = 0;

    // Gets the width and height, in pixels, of this image.
    virtual struct Size Size() const = 0;

    // Gets or sets an object that provides additional data about the image.
    virtual void *Tag() const;

    // Gets the vertical resolution, in pixels per inch, of this Image.
    virtual float VerticalResolution() const = 0;

    // Gets the width, in pixels, of this Image.
    virtual int Width() const = 0;

public: // Methods
    // Creates an exact copy of this Image.
    virtual Image *Clone() const = 0;

    // Releases all resources used by this Image.
    // System_CAPS_pubmethod	Dispose()

    // Releases the unmanaged resources used by the Image and optionally releases the managed resources.
    // System_CAPS_protmethod	Dispose(Boolean)

    // Allows an object to try to free resources and perform other cleanup operations before it is reclaimed by garbage collection.(Overrides Object.Finalize().)
    // System_CAPS_protmethod	Finalize()

    // Creates an Image from the specified file.
    static Image *FromFile(std::string const &filename);

    // Creates an Image from the specified file using embedded color management information in that file.
    static Image *FromFile(std::string const &filename, bool useEmbeddedColorManagement);

    // Creates an Image from the specified data stream.
    static Image *FromStream(std::istream &stream);

    // Creates an Image from the specified data stream, optionally using embedded color management information in that stream.
    static Image *FromStream(std::istream &stream, bool useEmbeddedColorManagement);

    // Creates an Image from the specified data stream, optionally using embedded color management information and validating the image data.
    static Image *FromStream(std::istream &stream, bool useEmbeddedColorManagement, bool validateImageData);

    // Gets the bounds of the image in the specified unit.
    virtual RectangleF GetBounds(GraphicsUnit &pageUnit) const = 0;

    // Returns information about the parameters supported by the specified image encoder.
    // System_CAPS_pubmethod	GetEncoderParameterList(Guid)

    // Returns the number of frames of the specified dimension.
    // System_CAPS_pubmethod	GetFrameCount(FrameDimension)

    // Serves as the default hash function. (Inherited from Object.)
    // System_CAPS_pubmethod	GetHashCode()

    // Returns the color depth, in number of bits per pixel, of the specified pixel format.
    // System_CAPS_pubmethodSystem_CAPS_static	GetPixelFormatSize(PixelFormat)

    // Gets the specified property item from this Image.
    // System_CAPS_pubmethod	GetPropertyItem(Int32)

    // Returns a thumbnail for this Image.
    // System_CAPS_pubmethod	GetThumbnailImage(Int32, Int32, Image.GetThumbnailImageAbort, IntPtr)

    // Gets the Type of the current instance.(Inherited from Object.)
    // System_CAPS_pubmethod	GetType()

    // Returns a value that indicates whether the pixel format for this Image contains alpha information.
    // System_CAPS_pubmethodSystem_CAPS_static	IsAlphaPixelFormat(PixelFormat)

    // Returns a value that indicates whether the pixel format is 32 bits per pixel.
    // System_CAPS_pubmethodSystem_CAPS_static	IsCanonicalPixelFormat(PixelFormat)

    // Returns a value that indicates whether the pixel format is 64 bits per pixel.
    // System_CAPS_pubmethodSystem_CAPS_static	IsExtendedPixelFormat(PixelFormat)

    // Removes the specified property item from this Image.
    // System_CAPS_pubmethod	RemovePropertyItem(Int32)

    // Rotates, flips, or rotates and flips the Image.
    virtual void RotateFlip(RotateFlipType rotateFlipType) = 0;

    // Saves this image to the specified stream in the specified format.
    virtual void Save(std::ostream &stream, Imaging::ImageFormat const &format) = 0;

    // Saves this Image to the specified file or stream.
    virtual void Save(std::string const &filename) = 0;

    // Saves this Image to the specified file in the specified format.
    virtual void Save(std::string const &filename, Imaging::ImageFormat const &format) = 0;

    // Selects the frame specified by the dimension and index.
    // System_CAPS_pubmethod SelectActiveFrame(FrameDimension, Int32)

    // Stores a property item (piece of metadata) in this Image.
    // System_CAPS_pubmethod SetPropertyItem(PropertyItem)

};

} // namespace Drawing
} // namespace System

#endif // IMAGE_H
