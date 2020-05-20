#include "LinesDrawEntity.h"
#include "Screen.h"


Uint32* gBuffer2 = nullptr;
SDL_Texture* gTexture2 = nullptr;

void LinesDrawEntity::Start()
{
    gTexture2 = SDL_CreateTexture(Screen::GetRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, Screen::GetSurface()->w, Screen::GetSurface()->h);
    if (gTexture2 == nullptr) {
        printf("Could not create texture. Error: %s\n", SDL_GetError());

    }
    else {
        //Create pixel buffer
        gBuffer2 = new Uint32[Screen::GetPixelsCount()];
        SDL_memset(gBuffer2, 0, Screen::GetPixelsCount() * sizeof(Uint32));
    }
}

void LinesDrawEntity::Update()
{

    //Perform any modifications on the pixels
    ModifyPixels();

    //Apply the pixel change to the texture
    SDL_UpdateTexture(gTexture2, NULL, gBuffer2, Screen::GetWidth() * sizeof(Uint32));

    //Render texture to screen
    SDL_SetTextureBlendMode(gTexture2, SDL_BLENDMODE_BLEND);
    SDL_RenderCopy(Screen::GetRenderer(), gTexture2, NULL, NULL);

    //Update screen to window
    //SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
    SDL_RenderPresent(Screen::GetRenderer());
    //  SDL_Delay(500);
}

void LinesDrawEntity::ModifyPixels()
{
    //Get window pixel format
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);


    //Set color data
    Uint32 yellow = SDL_MapRGBA(mappingFormat, 0xFA, 0xD3, 0x2C, 0x30);
    Uint32 gray = SDL_MapRGBA(mappingFormat, 0x1B, 0x22, 0x26, 0x30);
    //Color in certain pixels
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        if ((i % 400) == 0) {
            gBuffer2[i] = yellow;
        }
    }
}