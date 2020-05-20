#pragma once
#include "Entity.h"

class BaseInputEntity : public Entity
{
public:
	void OnEvent(SDL_Event e) override;
};