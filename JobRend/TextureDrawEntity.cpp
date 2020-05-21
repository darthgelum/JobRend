#include "TextureDrawEntity.h"

void TextureDrawEntity::Update()
{
    ModifyPixels();
}

void TextureDrawEntity::ModifyPixels()
{
    Uint32 red = MainCanvas::CColor(0xff,0x00,0x00);
    Uint32 green = MainCanvas::CColor(0x00, 0xff, 0x00);
    Uint32 blue = MainCanvas::CColor(0x00, 0x00, 0xff);
    
    MainCanvas* canvas = Screen::GetCanvas();
    //Color in certain pixels
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        Vector2 coords = canvas->GetCoordsOfPixel(i);
        if ((i % 50) == 0) {
            canvas->SetPixelColor(red, coords.x, coords.y);
        }
        if ((i % 1000) == 0) {
            canvas->SetPixelColor(green, coords.x, coords.y);
        }
        if ((i % 2000) == 0) {
            canvas->SetPixelColor(blue, coords.x, coords.y);
        }
    }
}