#include "Loader.h"

SDL_Texture* Loader::LoadTexture(SDL_Renderer *renderer,std::string path)
{
	std::string img_path = "images\\"+path;
	return IMG_LoadTexture(renderer, img_path.c_str());
}