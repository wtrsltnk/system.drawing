#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <system.drawing/Imaging/system.drawing.imaging.colorpalette.h>
#include <system.drawing/Imaging/system.drawing.imaging.encoderparameters.h>
#include <system.drawing/Imaging/system.drawing.imaging.imagecodecinfo.h>
#include <system.drawing/Imaging/system.drawing.imaging.imageformat.h>
#include <system.drawing/Imaging/system.drawing.imaging.pixelformat.h>
#include <system.drawing/system.drawing.graphicsunit.h>
#include <system.drawing/system.drawing.rectanglef.h>
#include <system.drawing/system.drawing.rotatefliptype.h>
#include <system.drawing/system.drawing.size.h>
#include <system.drawing/system.drawing.sizef.h>

typedef void *HBITMAP;
typedef void *HPALETTE;

namespace System {
namespace Drawing {

class Image
{
protected:
    int _flags;
    int _height;
    float _horizontalResolution;
    Imaging::ColorPalette *_palette;
    Imaging::PixelFormat _pixelFormat;
    Imaging::ImageFormat *_rawFormat;
    void *_tag;
    float _verticalResolution;
    int _width;

public: // Propeties
    // Gets attribute flags for the pixel data of this Image.
    int Flags() const;

    // Gets an array of GUIDs that represent the dimensions of frames within this Image.
    // System_CAPS_pubproperty	FrameDimensionsList

    // Gets the height, in pixels, of this Image.
    int Height() const;

    // Gets the horizontal resolution, in pixels per inch, of this Image.
    float HorizontalResolution() const;

    // Gets or sets the color palette used for this Image.
    Imaging::ColorPalette const *Palette() const;

    // Gets the width and height of this image.
    SizeF PhysicalDimension() const;

    // Gets the pixel format for this Image.
    Imaging::PixelFormat PixelFormat();

    // Gets IDs of the property items stored in this Image.
    // System_CAPS_pubproperty	PropertyIdList

    // Gets all the property items (pieces of metadata) stored in this Image.
    // System_CAPS_pubproperty	PropertyItems

    // Gets the file format of this Image.
    Imaging::ImageFormat *RawFormat();

    // Gets the width and height, in pixels, of this image.
    struct Size Size() const;

    // Gets or sets an object that provides additional data about the image.
    void *Tag() const;

    // Gets the vertical resolution, in pixels per inch, of this Image.
    float VerticalResolution() const;

    // Gets the width, in pixels, of this Image.
    int Width() const;

public: // Methods
    // Creates an exact copy of this Image.
    virtual Image *Clone() const = 0;

    // Creates an object that contains all the relevant information required to generate a proxy used to communicate with a remote object.(Inherited from MarshalByRefObject.)
    // System_CAPS_pubmethod	CreateObjRef(Type)

    // Releases all resources used by this Image.
    // System_CAPS_pubmethod	Dispose()

    // Releases the unmanaged resources used by the Image and optionally releases the managed resources.
    // System_CAPS_protmethod	Dispose(Boolean)

    // Determines whether the specified object is equal to the current object.(Inherited from Object.)
    // System_CAPS_pubmethod	Equals(Object)

    // Allows an object to try to free resources and perform other cleanup operations before it is reclaimed by garbage collection.(Overrides Object.Finalize().)
    // System_CAPS_protmethod	Finalize()

    // Creates an Image from the specified file.
    static Image *FromFile(std::string const &filename);

    // Creates an Image from the specified file using embedded color management information in that file.
    static Image *FromFile(std::string const &filename, bool useEmbeddedColorManagement);

    // Creates a Bitmap from a handle to a GDI bitmap.
    static Image *FromHbitmap(HBITMAP hbitmap);

    // Creates a Bitmap from a handle to a GDI bitmap and a handle to a GDI palette.
    static Image *FromHbitmap(HBITMAP hbitmap, HPALETTE hpalette);

    // Creates an Image from the specified data stream.
    static Image *FromStream(std::ofstream &stream);

    // Creates an Image from the specified data stream, optionally using embedded color management information in that stream.
    static Image *FromStream(std::ofstream &stream, bool useEmbeddedColorManagement);

    // Creates an Image from the specified data stream, optionally using embedded color management information and validating the image data.
    static Image *FromStream(std::ofstream &stream, bool useEmbeddedColorManagement, bool validateImageData);

    // Gets the bounds of the image in the specified unit.
    virtual RectangleF GetBounds(GraphicsUnit &pageUnit) const = 0;

    // Returns information about the parameters supported by the specified image encoder.
    // System_CAPS_pubmethod	GetEncoderParameterList(Guid)

    // Returns the number of frames of the specified dimension.
    // System_CAPS_pubmethod	GetFrameCount(FrameDimension)

    // Serves as the default hash function. (Inherited from Object.)
    // System_CAPS_pubmethod	GetHashCode()

    // Retrieves the current lifetime service object that controls the lifetime policy for this instance.(Inherited from MarshalByRefObject.)
    // System_CAPS_pubmethod	GetLifetimeService()

    // Returns the color depth, in number of bits per pixel, of the specified pixel format.
    // System_CAPS_pubmethodSystem_CAPS_static	GetPixelFormatSize(PixelFormat)

    // Gets the specified property item from this Image.
    // System_CAPS_pubmethod	GetPropertyItem(Int32)

    // Returns a thumbnail for this Image.
    // System_CAPS_pubmethod	GetThumbnailImage(Int32, Int32, Image.GetThumbnailImageAbort, IntPtr)

    // Gets the Type of the current instance.(Inherited from Object.)
    // System_CAPS_pubmethod	GetType()

    // Obtains a lifetime service object to control the lifetime policy for this instance.(Inherited from MarshalByRefObject.)
    // System_CAPS_pubmethod	InitializeLifetimeService()

    // Returns a value that indicates whether the pixel format for this Image contains alpha information.
    // System_CAPS_pubmethodSystem_CAPS_static	IsAlphaPixelFormat(PixelFormat)

    // Returns a value that indicates whether the pixel format is 32 bits per pixel.
    // System_CAPS_pubmethodSystem_CAPS_static	IsCanonicalPixelFormat(PixelFormat)

    // Returns a value that indicates whether the pixel format is 64 bits per pixel.
    // System_CAPS_pubmethodSystem_CAPS_static	IsExtendedPixelFormat(PixelFormat)

    // Creates a shallow copy of the current Object.(Inherited from Object.)
    // System_CAPS_protmethod	MemberwiseClone()

    // Creates a shallow copy of the current MarshalByRefObject object.(Inherited from MarshalByRefObject.)
    // System_CAPS_protmethod	MemberwiseClone(Boolean)

    // Removes the specified property item from this Image.
    // System_CAPS_pubmethod	RemovePropertyItem(Int32)

    // Rotates, flips, or rotates and flips the Image.
    virtual void RotateFlip(RotateFlipType rotateFlipType) = 0;

    // Saves this image to the specified stream, with the specified encoder and image encoder parameters.
    virtual void Save(std::ostream &stream, Imaging::ImageCodecInfo const &encoder, Imaging::EncoderParameters const &encoderParams) = 0;

    // Saves this image to the specified stream in the specified format.
    virtual void Save(std::ostream &stream, Imaging::ImageFormat const &format) = 0;

    // Saves this Image to the specified file or stream.
    virtual void Save(std::string const &filename) = 0;

    // Saves this Image to the specified file, with the specified encoder and image-encoder parameters.
    virtual void Save(std::string const &filename, Imaging::ImageCodecInfo const &encoder, Imaging::EncoderParameters const &encoderParams) = 0;

    // Saves this Image to the specified file in the specified format.
    virtual void Save(std::string const &filename, Imaging::ImageFormat const &format) = 0;

    // Adds a frame to the file or stream specified in a previous call to the Save method. Use this method to save selected frames from a multiple-frame image to another multiple-frame image.
    virtual void SaveAdd(Imaging::EncoderParameters const &encoderParams) = 0;

    // Adds a frame to the file or stream specified in a previous call to the Save method.
    virtual void SaveAdd(Image *image, Imaging::EncoderParameters const &encoderParams) = 0;

    // Selects the frame specified by the dimension and index.
    // System_CAPS_pubmethod SelectActiveFrame(FrameDimension, Int32)

    // Stores a property item (piece of metadata) in this Image.
    // System_CAPS_pubmethod SetPropertyItem(PropertyItem)

    // Returns a string that represents the current object.(Inherited from Object.)
    // System_CAPS_pubmethod ToString()
};

} // namespace Drawing
} // namespace System

#endif // IMAGE_H
