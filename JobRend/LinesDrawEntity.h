#pragma once
#include "Entity.h"
#include <SDL.h>
class LinesDrawEntity : public Entity
{
public:
	void Start() override;
	void Update() override;
private:
	void ModifyPixels();
};

