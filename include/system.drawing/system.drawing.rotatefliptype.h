#ifndef ROTATEFLIPTYPE_H
#define ROTATEFLIPTYPE_H

enum class RotateFlipType
{
    // Specifies a 180-degree clockwise rotation without flipping.
    Rotate180FlipNone,

    // Specifies a 180-degree clockwise rotation followed by a horizontal flip.
    Rotate180FlipX,

    // Specifies a 180-degree clockwise rotation followed by a horizontal and vertical flip.
    Rotate180FlipXY,

    // Specifies a 180-degree clockwise rotation followed by a vertical flip.
    Rotate180FlipY,

    // Specifies a 270-degree clockwise rotation without flipping.
    Rotate270FlipNone,

    // Specifies a 270-degree clockwise rotation followed by a horizontal flip.
    Rotate270FlipX,

    // Specifies a 270-degree clockwise rotation followed by a horizontal and vertical flip.
    Rotate270FlipXY,

    // Specifies a 270-degree clockwise rotation followed by a vertical flip.
    Rotate270FlipY,

    // Specifies a 90-degree clockwise rotation without flipping.
    Rotate90FlipNone,

    // Specifies a 90-degree clockwise rotation followed by a horizontal flip.
    Rotate90FlipX,

    // Specifies a 90-degree clockwise rotation followed by a horizontal and vertical flip.
    Rotate90FlipXY,

    // Specifies a 90-degree clockwise rotation followed by a vertical flip.
    Rotate90FlipY,

    // Specifies no clockwise rotation and no flipping.
    RotateNoneFlipNone,

    // Specifies no clockwise rotation followed by a horizontal flip.
    RotateNoneFlipX,

    // Specifies no clockwise rotation followed by a horizontal and vertical flip.
    RotateNoneFlipXY,

    // Specifies no clockwise rotation followed by a vertical flip.
    RotateNoneFlipY,

};

#endif // ROTATEFLIPTYPE_H
