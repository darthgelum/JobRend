#include "MainCanvas.h"
#include "Screen.h"
#include <array>
#include "Color.h"
MainCanvas::MainCanvas()
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

Uint32 MainCanvas::CColor(int r, int g, int b, int a) {
   
    return SDL_MapRGBA(mappingFormat, r, g, b, a);
};

void MainCanvas::DrawLine(Vector3 vertex1, Vector3 vertex2, Uint32 color)
{

    // Coord + centerization 
    int x0 = vertex1.x + CenterPoint().x;
    int y0 = -vertex1.y + CenterPoint().y;
    int x1 = vertex2.x + CenterPoint().x;
    int y1 =  -vertex2.y + CenterPoint().y;
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

void MainCanvas::ColorTriangle(Vector3 a, Vector3 b, Vector3 c)
{
    Color col0 = Color::Black;
    Color col1 = Color::Yellow;
    Color col2 = Color::Red;

    int cx = CenterPoint().x;
    int cy = CenterPoint().y;
   
    int dCol0[] = { col1.r - col0.r, col1.g - col0.g, col1.b - col0.b };
    int dCol1[] = { col2.r - col0.r, col2.g - col0.g, col2.b - col0.b };

    int topLeft[2] = { std::min({a.x,b.x,c.x}),std::min({a.y,b.y,c.y}) };
    int bottomRight[2] = { std::max({a.x,b.x,c.x}),std::max({a.y,b.y,c.y}) };

    Uint8 dR = 0;
    Uint8 dG = 0;
    Uint8 dB = 0;

    for (int y = topLeft[1]; y < bottomRight[1]; y++)
    {
        bool hasColoredInline = false;
        for (int x = topLeft[0]; x < bottomRight[0]; x++)
        {
            float w1 =   (a.x * (c.y - a.y) + (y - a.y)*(c.x - a.x) - x*(c.y - a.y))/
                     //-------------------------------------------------------------------
                            ((b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y));
            if (w1 >= 0)
            {
                float w2 = (y - a.y - w1 * (b.y - a.y)) / (c.y - a.y);
                if (w2 >= 0 && w1+w2<=1)
                {
                     dR = w1 * dCol0[0] + w2 * dCol1[0] + col0.r;
                     dG = w1 * dCol0[1] + w2 * dCol1[1] + col0.g;
                     dB = w1 * dCol0[2] + w2 * dCol1[2] + col0.b;
                   
                    SetPixelColor((dR << 24) | (dG << 16) | (dB << 8) | 255, x + cx, -y + cy);
                    hasColoredInline = true;
                }
                else
                {
                    if(hasColoredInline)
                    {
                       break;
                    }
                }
            }
            else
            {
                if (hasColoredInline)
                {
                    break;
                }
            }

            //aSide = (a.y - b.y) * x + (b.x - a.x) * y + (a.x * b.y - b.x * a.y);
            //bSide = (b.y - c.y) * x + (c.x - b.x) * y + (b.x * c.y - c.x * b.y);
            //cSide = (c.y - a.y) * x + (a.x - c.x) * y + (c.x * a.y - a.x * c.y);
     /*       if ((aSide >= 0 && bSide >= 0 && cSide >= 0) || (aSide < 0 && bSide < 0 && cSide < 0))
            {
                SetPixelColor(white,x+ CenterPoint().x,-y + CenterPoint().y);
            }*/
        }
    }
    return;
   
}

void MainCanvas::SetPixelColor(Uint32 color, int x, int y)
{

    if (x < 0 || y < 0 || x>width || y>height)
    {
        return;
    }

    gBuffer[((y * width) + x)] = color;
}

void MainCanvas::SetPixelColor(Uint32 color, Uint32* pixel)
{
    *pixel = color;
}


Vector2 MainCanvas::GetCoordsOfPixel(int number)
{
    return Vector2(floor(number% GetWidth()), floor(number / GetWidth()));
}

int MainCanvas::convertCoordinates(int x, int y)
{
    return ((y * width) + x);
}

void MainCanvas::Render()
{
	texture->updateTexture(gBuffer);
	texture->renderToScreen(Screen::GetRenderer());
}