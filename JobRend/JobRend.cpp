// JobRend.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <string>
#include "Resolutions.h"
#include "SDL.h"
#include "SDL_image.h"
#include "EntityContainer.h"
#include "ScreenStates.h"
#include "Engine.h"
#include "SDLSoftwareRenderer.h"
int main()
{
    Engine::SetRender(new SDLSoftwareRenderer(800,600));
    
    return Engine::MainLoop();
}


