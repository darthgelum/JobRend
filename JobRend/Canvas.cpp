#include "MainCanvas.h"
#include "Screen.h"
Canvas::Canvas()
{
    width = Screen::GetSurface()->w;
    height = Screen::GetSurface()->h;
    center = Vector2(Screen::GetSurface()->w/2, Screen::GetSurface()->h/2);
	texture = new Texture(Screen::GetRenderer(), width,height);
	gBuffer = new Uint32[Screen::GetPixelsCount()];
    mappingFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        gBuffer[i] = CColor(0x00,0x00,0x00);
    }
}

Uint32 Canvas::CColor(int r, int g, int b, int a) {
   
    return SDL_MapRGBA(mappingFormat, r, g, b, a);
};

void Canvas::DrawLine(Vector3 vertex1, Vector3 vertex2, Uint32 color)
{


}

Uint32* Canvas::SetPixelColor(Uint32 color, int x, int y)
{

    if (x < 0 || y < 0 || x>width || y>height)
    {
        return &gBuffer[0];
    }

    int pixelNumber = convertCoordinates(x, y);

    gBuffer[pixelNumber] = color;
    return &gBuffer[pixelNumber];
}

Uint32* Canvas::SetPixelColor(Uint32 color, Uint32* pixel)
{
    *pixel = color;
    return pixel;
}


Vector2 Canvas::GetCoordsOfPixel(int number)
{
    return Vector2(floor(number% GetWidth()), floor(number / GetWidth()));
}

int Canvas::convertCoordinates(int x, int y)
{
    return ((y * width) + x);
}

void Canvas::Render()
{
	texture->updateTexture(gBuffer);
	texture->renderToScreen(Screen::GetRenderer());
}