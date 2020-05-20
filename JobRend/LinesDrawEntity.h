#pragma once
#include "Entity.h"
#include <SDL.h>
class LinesDrawEntity : public Entity
{
public:
	void Start() override;
	void Update() override;
private:
	Uint32* gBuffer = nullptr;
	SDL_Texture* gTexture = nullptr;
	void ModifyPixels();
};

