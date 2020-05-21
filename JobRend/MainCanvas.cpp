#include "MainCanvas.h"
#include "Screen.h"
MainCanvas::MainCanvas()
{
	texture = new Texture(Screen::GetRenderer(), Screen::GetSurface()->w, Screen::GetSurface()->h);
	gBuffer = new Uint32[Screen::GetPixelsCount()];
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);
    Uint32 black = SDL_MapRGBA(mappingFormat, 0x00, 0x00,0x00, 0xff);
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        gBuffer[i] = black;
    }
}
void MainCanvas::Render()
{
	texture->updateTexture(gBuffer);
	texture->renderToScreen(Screen::GetRenderer());
}