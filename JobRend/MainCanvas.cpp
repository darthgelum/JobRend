#include "MainCanvas.h"
#include "Screen.h"
MainCanvas::MainCanvas()
{
    center = Vector2(Screen::GetSurface()->w/2, Screen::GetSurface()->h/2);
	texture = new Texture(Screen::GetRenderer(), Screen::GetSurface()->w, Screen::GetSurface()->h);
	gBuffer = new Uint32[Screen::GetPixelsCount()];
    mappingFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        gBuffer[i] = CColor(0x00,0x00,0x00);
    }
}

Uint32 MainCanvas::CColor(int r, int g, int b, int a) {
   
    return SDL_MapRGBA(mappingFormat, r, g, b, a);
};

void MainCanvas::SetPixelColor(Uint32 color, int x, int y)
{
    int pixelNumber = convertCoordinates(x, y);
    gBuffer[pixelNumber] = color;
}

Vector2 MainCanvas::GetCoordsOfPixel(int number)
{
    return Vector2(floor(number% GetWidth()), floor(number / GetWidth()));
}

int MainCanvas::convertCoordinates(int x, int y)
{
    return ((y * GetWidth()) + x);
}

void MainCanvas::Render()
{
	texture->updateTexture(gBuffer);
	texture->renderToScreen(Screen::GetRenderer());
}