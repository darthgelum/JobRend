#pragma once
#include <SDL.h>
#include <iostream>
#include <stdexcept>
#include "Resolutions.h"


class Screen
{
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Surface* surface;

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




