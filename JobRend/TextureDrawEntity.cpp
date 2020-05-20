#include "TextureDrawEntity.h"
#include "Screen.h"



void TextureDrawEntity::Start()
{
    texture = new Texture(Screen::GetRenderer(), Screen::GetSurface()->w, Screen::GetSurface()->h);
    gbuffer = Screen::GetGBuffer();
    //gTexture = SDL_CreateTexture(Screen::GetRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, Screen::GetSurface()->w, Screen::GetSurface()->h);
    //if (gTexture == nullptr) {
    //    printf("Could not create texture. Error: %s\n", SDL_GetError());

    //}
    //else {
    //    //Create pixel buffer
    //    gBuffer = new Uint32[Screen::GetPixelsCount()];
    //    SDL_memset(gBuffer, 0, Screen::GetPixelsCount() * sizeof(Uint32));
    //}


}

void TextureDrawEntity::Update()
{
    //Perform any modifications on the pixels
    ModifyPixels();
    texture->renderToScreen(Screen::GetRenderer());
    ////Apply the pixel change to the texture
    //SDL_UpdateTexture(gTexture, NULL, gBuffer, Screen::GetWidth() * sizeof(Uint32));

    ////Render texture to screen
    //SDL_RenderCopy(Screen::GetRenderer(), gTexture, NULL, NULL);

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
    //Color in certain pixels
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        if ((i % 50) == 0) {
            gbuffer[i] = red1;
        }
        if ((i % 1000) == 0) {
            gbuffer[i] = green;
        }
        if ((i % 2000) == 0) {
            gbuffer[i] = blue;
        }
    }
    texture->updateTexture(gbuffer);
}