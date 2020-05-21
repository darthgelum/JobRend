#pragma once
#include <SDL_events.h>
#include "Screen.h"
#include "MainCanvas.h"
class Entity
{
public:
	virtual void Start() {};
	virtual void Update() {};
	virtual void OnEvent(SDL_Event e) {};
};
