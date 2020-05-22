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

void MainCanvas::DrawLine(Vector3 vertex1, Vector3 vertex2, Uint32 color)
{
    int scalingFactor = 3;
    // Coord + centerization (center on x, 2/3 on y)
    int x0 = (vertex1.x * scalingFactor) + GetWidth() * 1 / 2;
    int y0 = (-vertex1.y * scalingFactor) + GetHeight();
    int x1 = (vertex2.x * scalingFactor) + GetWidth() * 1 / 2;
    int y1 = (-vertex2.y * scalingFactor) + GetHeight();
    // Bresenheim algo
    const int deltaX = abs(x1 - x0);
    const int deltaY = abs(y1 - y0);
    const int signX = x0 < x1 ? 1 : -1;
    const int signY = y0 < y1 ? 1 : -1;

    int error = deltaX - deltaY;
    int error2 = 0;
    //last point
    SetPixelColor(color,x1, y1);
    while (x0 != x1 || y0 != y1)
    {
        SetPixelColor(color, x0, y0);
        error2 = error << 1 ;
        //
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x0 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y0 += signY;
        }
    }
}

Uint32* MainCanvas::SetPixelColor(Uint32 color, int x, int y)
{
    if (x < 0 || y < 0 || x>GetWidth() || y>GetHeight())
    {
        return &gBuffer[0];
    }
    int pixelNumber = convertCoordinates(x, y);
    gBuffer[pixelNumber] = color;
    return &gBuffer[pixelNumber];
}

Uint32* MainCanvas::SetPixelColor(Uint32 color, Uint32* pixel)
{
    *pixel = color;
    return pixel;
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