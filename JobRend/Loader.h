#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
class Loader
{
	public:
		static SDL_Texture* LoadTexture(SDL_Renderer *renderer, std::string path);
};

