#pragma once
#include "Entity.h"
#include <SDL.h>
#include "Texture.h"
class LinesDrawEntity : public Entity
{
public:
	void Update() override;
private:
	void ModifyPixels();
};

