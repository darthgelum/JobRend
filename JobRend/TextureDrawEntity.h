#pragma once
#include "Entity.h"
#include <SDL.h>
class TextureDrawEntity : public Entity
{
public:
	void Start() override;
	void Update() override;
private:
	void ModifyPixels();

};