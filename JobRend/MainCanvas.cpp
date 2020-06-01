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
    //Uint32 red = CColor(0xFF, 0x00, 0x00);
    //Uint32 green = CColor(0x00, 0xFF, 0x00);
    //Uint32 blue = CColor(0x00, 0x00, 0xFF);
    Color red = Color::Red;
    Color green = Color::Green;
    Color blue = Color::Blue;
    Color dColor0 = blue-red;
    Color dColor1 = green - red;
    int topLeft[2] = { std::min({a.x,b.x,c.x}),std::min({a.y,b.y,c.y}) };
    int bottomRight[2] = { std::max({a.x,b.x,c.x}),std::max({a.y,b.y,c.y}) };
    
    int aSide = 0;
    int bSide = 0;
    int cSide = 0;


    for (int y = topLeft[1]; y < bottomRight[1]; y++)
    {
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
                    Color result = Color(255 - (255 * w1) - (255 * w2), 0 + (255 * w1), 0 + (255 * w2));
                    SetPixelColor(result.toInteger(), x + CenterPoint().x, -y + CenterPoint().y);
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

    int pixelNumber = convertCoordinates(x, y);

    gBuffer[pixelNumber] = color;
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