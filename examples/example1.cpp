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
    image->Save("c:/temp/nova-copy.tga");
    return 0;
}
