#include "LinesDrawEntity.h"
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Converters.h"

void LinesDrawEntity::Update()
{

    //Perform any modifications on the pixels
    ModifyPixels();
}
int counter;
bool frame_switched = false;
bool rand_c = false;
int r = 0;
int g = 0;
int b = 0;
void LinesDrawEntity::ModifyPixels()
{
    counter++;

    if (counter > 5)
    {
        r = (rand() % 256);
        g = (rand() % 256);
        b = (rand() % 256);
        counter = 0;
    }
    //Get window pixel format
    Uint32 format = SDL_PIXELFORMAT_RGBA8888;
    SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);

    //Set color data
    Uint32 randcolor = SDL_MapRGBA(mappingFormat, Converters::IntToHex(r), Converters::IntToHex(g), Converters::IntToHex(b), 0xff);
  //  Uint32 gray = SDL_MapRGBA(mappingFormat, 0x1B, 0x22, 0x26, 0x30);
    //Color in certain pixels

    int col = 0;
    int row = 0;
    bool flag = false;
    bool row_sw = false;
    // pixels in chess order
    for (int i = 0; i < Screen::GetPixelsCount(); ++i) {
        col = floor(i%Screen::GetWidth());
        row = floor(i / Screen::GetWidth());
        flag = (!row_sw && col % 2 != 0) || (row_sw && col % 2 == 0) ? false : true;
        Uint32* gBuffer = Screen::GetCanvas()->GetGBuffer();
        if (flag^frame_switched)
        {
            gBuffer[i] = randcolor;
        }
        if (col != 0 && col % (Screen::GetWidth() - 1) == 0)
        {
            row_sw = !row_sw;
        }
    }
    frame_switched = !frame_switched;
}