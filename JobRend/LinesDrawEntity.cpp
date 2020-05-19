#include "LinesDrawEntity.h"
#include "Screen.h"


void LinesDrawEntity::Start()
{
    Uint32* pixels = (Uint32*)Screen::Surface()->pixels;
    int size = Screen::Surface()->h * Screen::Surface()->w;
    for (int i = 0; i < size; i++) {
        if ((i % 200) == 0)
        {
            pixels[i] = 0xfad32c;
        }
        else
        {
            pixels[i] = 0x1b2226;
        }
    }
}