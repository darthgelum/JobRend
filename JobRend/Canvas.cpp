#include "Canvas.h"
#include "Screen.h"
Canvas::Canvas()
{
	texture = new Texture(Screen::GetRenderer(), Screen::GetSurface()->w, Screen::GetSurface()->h);
    gBuffer = new Uint32[ Screen::GetPixelsCount() ];

}

Uint32 Canvas::CColor(int r, int g, int b, int a) {
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);
    return SDL_MapRGBA(mappingFormat, r, g, b, a);
};

void Canvas::SetPixelColor(Uint32 color, int x, int y)
{
    int pixelNumber = convertCoordinates(x, y);
    gBuffer[pixelNumber] = color;
}

Vector2 Canvas::GetCoordsOfPixel(int number)
{
    return Vector2(floor(number% GetWidth()), floor(number / GetWidth()));
}

int Canvas::convertCoordinates(int x, int y)
{
    return ((y * GetWidth()) + x);
}
void Canvas::ClearBuffer()
{
    gBuffer = new Uint32[Screen::GetPixelsCount()];
}
void Canvas::Render()
{
	texture->updateTexture(gBuffer);
	texture->renderToScreen(Screen::GetRenderer());
}