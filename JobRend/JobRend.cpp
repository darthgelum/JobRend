// JobRend.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <string>
#include "Resolutions.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Directories.h"
#include "Converters.h"
#include "Screen.h"
#include "EntityContainer.h"

int main()
{
    SDL_Window* window = Screen::Window();
    SDL_Surface* surface = Screen::Surface();
    int memSize = surface->h * surface->pitch;
    int size = surface->h * surface->w;

    EntityContainer* cont = new EntityContainer();

    for (Entity* e : cont->GetAll())
    {
        e->Start();
    }
    //Modify pixels
    Uint32* pixels = (Uint32*)surface->pixels;
    for (int i = 0; i < size; i++) {
        if ((i % 200) == 0 )
        {
            pixels[i] = 0xfad32c;
        }
        else
        {
            pixels[i] = 0x1b2226;
        }
    }

    while (1) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
            else
            {
                for (Entity* en : cont->GetAll())
                {
                    en->OnEvent(e);
                }
            }
        }
        for (Entity* e : cont->GetAll())
        {
            e->Update();
        }
        SDL_UpdateWindowSurface(window);
    }

    Screen::Destroy();
    return 0;
}


