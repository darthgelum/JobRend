#include "LinesDrawEntity.h"
#include "Screen.h"


void LinesDrawEntity::Start()
{
    gTexture = SDL_CreateTexture(Screen::GetRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, Screen::GetWidth(), Screen::GetHeight());
    if (gTexture == nullptr) {
        printf("Could not create texture. Error: %s\n", SDL_GetError());

    }
    else {
        //Create pixel buffer
        gBuffer = new Uint32[Screen::GetPixelsCount()];
        SDL_memset(gBuffer, 0, Screen::GetPixelsCount() * sizeof(Uint32));
    }
    SDL_SetTextureBlendMode(gTexture, SDL_BLENDMODE_BLEND);

}

void LinesDrawEntity::Update()
{

    //Perform any modifications on the pixels
    ModifyPixels();

    //Apply the pixel change to the texture
    SDL_UpdateTexture(gTexture, NULL, gBuffer, Screen::GetWidth() * sizeof(Uint32));

    SDL_RenderCopy(Screen::GetRenderer(), gTexture, NULL, NULL);
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
            gBuffer[i] = yellow;
        }
    }
}