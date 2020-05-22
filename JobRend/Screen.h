#pragma once
#include <SDL.h>
#include <iostream>
#include <stdexcept>
#include "Resolutions.h"
#include "MainCanvas.h"


class Screen
{

public:
	static SDL_Window* GetWindow()
	{
		if (window == NULL)
		{
			InitWindow(SDRes);
		}
		return window;
	}

	static SDL_Renderer* GetRenderer()
	{
		if (renderer == NULL)
		{
			InitRenderer();
		}
		return renderer;
	}

	static SDL_Surface* GetSurface()
	{
		if (surface == NULL)
		{
			InitSurface();
		}
		return surface;
	}
	static int	GetWidth()
	{
		if (width == 0)
		{
			width = GetSurface()->w;
		}
		return width;
	};
	static int	GetHeight()
	{
		if (height == 0)
		{
			height = GetSurface()->w;
		}
		return height;
	};
	static int	GetPixelsCount() 
	{
		if (pixelsCount == 0)
		{
			pixelsCount = GetHeight()*GetWidth();
		}
		return pixelsCount;
	};

	static MainCanvas* GetCanvas() {
		return mainCanvas;
	};
	static void Clear();
	static void InitRenderer();
	static void InitWindow(int width, int height, SDL_WindowFlags flag = SDL_WINDOW_OPENGL);
	static void InitSurface();
	static void Destroy();

private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Surface* surface;
	static MainCanvas* mainCanvas;
	static int width;
	static int height;
	static int pixelsCount;

};




