#ifndef GRAPHICSUNIT_H
#define GRAPHICSUNIT_H

enum class GraphicsUnit
{
    // Specifies the unit of measure of the display device. Typically pixels for video displays, and 1/100 inch for printers.
    Display,

    // Specifies the document unit (1/300 inch) as the unit of measure.
    Document,

    // Specifies the inch as the unit of measure.
    Inch,

    // Specifies the millimeter as the unit of measure.
    Millimeter,

    // Specifies a device pixel as the unit of measure.
    Pixel,

    // Specifies a printer's point (1/72 inch) as the unit of measure.
    Point,

    // Specifies the world coordinate system unit as the unit of measure.
    World,
};

#endif // GRAPHICSUNIT_H
