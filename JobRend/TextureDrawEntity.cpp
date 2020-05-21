#include "TextureDrawEntity.h"
#include "Screen.h"



void TextureDrawEntity::Update()
{
    ModifyPixels();
}

void TextureDrawEntity::ModifyPixels()
{
    //Get window pixel format
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);

    //Set color data
    Uint32 red1 = SDL_MapRGBA(mappingFormat, 0xFF, 0x00, 0x00, 0xff);
    Uint32 green = SDL_MapRGBA(mappingFormat, 0x00, 0xFF, 0x00, 0xff);
    Uint32 blue = SDL_MapRGBA(mappingFormat, 0x00, 0x00, 0xFF, 0xff);
    Uint32* gBuffer = Screen::GetCanvas()->GetGBuffer();
    //Color in certain pixels
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        if ((i % 50) == 0) {
            gBuffer[i] = red1;
        }
        if ((i % 1000) == 0) {
            gBuffer[i] = green;
        }
        if ((i % 2000) == 0) {
            gBuffer[i] = blue;
        }
    }
}