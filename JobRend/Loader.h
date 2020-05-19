#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
class Loader
{
	public:
		static SDL_Texture* LoadTexture(SDL_Renderer *renderer, std::string path);
};

SDL_Texture* Loader::LoadTexture(SDL_Renderer* renderer, std::string path)
{
	std::string img_path = "images\\" + path;
	return IMG_LoadTexture(renderer, img_path.c_str());
}