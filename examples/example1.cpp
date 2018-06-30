#include <iostream>
#include <system.drawing/system.drawing.bitmap.h>

using namespace System::Drawing;

int main(int argc, char *argv[])
{
    auto image = Image::FromFile("nova.jpg");
    image->Save("c:/temp/nova-copy.jpg");
    image->Save("c:/temp/nova-copy", Imaging::ImageFormat::Jpeg());
    image->Save("c:/temp/nova-copy.png");
    image->Save("c:/temp/nova-copy.bmp");
    Bitmap a((Bitmap*)image);
    a.Save("c:/temp/nova-copy.tga");
    Bitmap b((Bitmap*)image, 100, 100);
    b.Save("c:/temp/nova-resized.jpg");
    Bitmap((Bitmap*)image, 1000, 1000).Save("c:/temp/nova-resized-large.jpg");
    return 0;
}
