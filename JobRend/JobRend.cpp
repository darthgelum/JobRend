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
#include "ScreenStates.h"
int main()
{
    SDL_Window* window = Screen::GetWindow();
    SDL_Surface* surface = Screen::GetSurface();

    EntityContainer* cont = new EntityContainer();

    ScreenState::SetState(ScreenStateEnum::RUN);
    for (Entity* e : cont->GetAll())
    {
        e->Start();
    }

    while (ScreenState::GetState() ==  ScreenStateEnum::RUN) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            for (Entity* en : cont->GetAll())
            {
                en->OnEvent(e);
            }
        }
        Screen::Clear();
        for (Entity* e : cont->GetAll())
        {
            e->Update();
        }
        Screen::GetCanvas()->Render();
        SDL_RenderPresent(Screen::GetRenderer());
    }
    delete cont;
    Screen::Destroy();
    return 0;
}


