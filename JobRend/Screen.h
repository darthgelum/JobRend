#pragma once
#include <SDL.h>
#include <iostream>
#include <stdexcept>
#include "Resolutions.h"


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* surface = NULL;

class Screen
{
public:
	static SDL_Window* Window()
	{
		if (window == NULL)
		{
			InitWindow(SDRes);
		}
		return window;
	}

	static SDL_Renderer* Renderer()
	{
		if (renderer == NULL)
		{
			InitRenderer();
		}
		return renderer;
	}

	static SDL_Surface* Surface()
	{
		if (surface == NULL)
		{
			InitSurface();
		}
		return surface;
	}	
	static void InitRenderer();
	static void InitWindow(int width, int height, SDL_WindowFlags flag = SDL_WINDOW_OPENGL);
	static void InitSurface();
	static void Destroy();
};

void Screen::InitRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Screen::InitWindow(int width, int height, SDL_WindowFlags flag)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"JobRend",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width, height, flag
	);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		throw std::invalid_argument("Window initialisation error");
	}
}

void Screen::InitSurface()
{
	surface = SDL_GetWindowSurface(window);
}

 void Screen::Destroy()
{
	     SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



