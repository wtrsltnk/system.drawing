#ifndef ENCODERPARAMETERS_H
#define ENCODERPARAMETERS_H

#include <system.drawing/Imaging/system.drawing.imaging.encoderparameter.h>
#include <vector>

namespace System {
namespace Drawing {
namespace Imaging {

class EncoderParameters
{
public: // Constructors
    // Initializes a new instance of the EncoderParameters class that can contain one EncoderParameter object.
    EncoderParameters();

    // Initializes a new instance of the EncoderParameters class that can contain the specified number of EncoderParameter objects.
    EncoderParameters(int count);

public: // Properties
    // Gets or sets an array of EncoderParameter objects.
    std::vector<EncoderParameter> const &Param() const;
};

} // namespace Imaging
} // namespace Drawing
} // namespace System

#endif // ENCODERPARAMETERS_H
