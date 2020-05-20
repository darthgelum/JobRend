#pragma once
#include "Entity.h"
#include <SDL.h>
#include "Texture.h"
class TextureDrawEntity : public Entity
{
public:
	void Start() override;
	void Update() override;
private:
	Uint32* gbuffer = nullptr;
	Texture* texture = nullptr;
	void ModifyPixels();
};