#include "Screen.h"

int Screen::width = 0;
int Screen::height = 0;
int Screen::pixelsCount = 0;
SDL_Window* Screen::window;
SDL_Renderer* Screen::renderer;
SDL_Surface* Screen::surface;
MainCanvas* Screen::mainCanvas;

void Screen::InitRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
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
	mainCanvas = new MainCanvas();
}

void Screen::Clear()
{

	SDL_RenderClear(renderer);
	memset(mainCanvas->GetGBuffer(), 0, mainCanvas->GetPitch() * mainCanvas->GetHeight());

}
void Screen::Destroy()
{
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
