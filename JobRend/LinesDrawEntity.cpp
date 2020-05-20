#include "LinesDrawEntity.h"
#include "Screen.h"


void LinesDrawEntity::Start()
{
    texture = new Texture(Screen::GetRenderer(), Screen::GetSurface()->w, Screen::GetSurface()->h);
    gbuffer = Screen::GetGBuffer();
}

void LinesDrawEntity::Update()
{

    //Perform any modifications on the pixels
    ModifyPixels();

    //Apply the pixel change to the texture
    texture->updateTexture(gbuffer);
    texture->renderToScreen(Screen::GetRenderer());
}
int p = 0;
 bool p_switched = false;
void LinesDrawEntity::ModifyPixels()
{
    //Get window pixel format
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);
    if (p > 255)
    {
        p = 255;
        p_switched = true;
    }
    else if (p < 0)
    {
        p = 0;
        p_switched = false;
    }

    int a = p;
    if (p_switched)
    {
        p -= 15;
    }
    else
    {
        p += 15;
    }
    //Set color data
    Uint32 yellow = SDL_MapRGBA(mappingFormat, 0xFA, 0xD3, 0x2C, a);
    Uint32 gray = SDL_MapRGBA(mappingFormat, 0x1B, 0x22, 0x26, 0x30);
    //Color in certain pixels
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        if (i>0 &&(i % i) == 0) {
            gbuffer[i] = yellow;
        }
    }
}