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

    while (1) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            for (Entity* en : cont->GetAll())
            {
                en->OnEvent(e);
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


