// JobRend.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include "SDL.h"
#include"Resolutions.h";
#include "SDL_image.h"
#include "Directories.h"
#include <string>
int main()
{
    SDL_Window* window;    
    SDL_Renderer* renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);  

    window = SDL_CreateWindow(
        "JobRend",
        SDL_WINDOWPOS_UNDEFINED,    
        SDL_WINDOWPOS_UNDEFINED,   
        SDRes 
    );
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* img = NULL;
    int w, h; 
    std::string img_path = "images\\balthier.png";
    img = IMG_LoadTexture(renderer,img_path.c_str());
    SDL_QueryTexture(img, NULL,NULL, &w, &h);
    SDL_Rect texr; texr.x = 120; texr.y =0; texr.w = w; texr.h = h;
    while (1) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img, NULL, &texr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
