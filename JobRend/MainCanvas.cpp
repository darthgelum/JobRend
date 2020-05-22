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
    int scalingFactor = 18;
    // Coord + centerization (center on x, 2/3 on y)
    int x1 = (vertex1.x * scalingFactor) + GetWidth() * 1 / 2;
    int y1 = (-vertex1.y * scalingFactor) + GetHeight() * 2 / 3;
    int x2 = (vertex2.x * scalingFactor) + GetWidth() * 1 / 2;
    int y2 = (-vertex2.y * scalingFactor) + GetHeight() * 2 / 3;

    bool steep = false;
    if (std::abs(x1 - x2) < std::abs(y1 - y2)) {
        std::swap(x1, y1);
        std::swap(x2, y2);
        steep = true;
    }

    //Redefine line so that it is left to right
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int derror2 = std::abs(dy) * 2;
    int error2 = 0;
    int y = y1;
    for (int x = x1; x <= x2; x++) {
        if (steep) {
            SetPixelColor(color, y, x);
        }
        else {
            SetPixelColor(color, x, y);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y2 > y1 ? 1 : -1);
            error2 -= dx * 2;
        }
    }
}

Uint32* MainCanvas::SetPixelColor(Uint32 color, int x, int y)
{
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