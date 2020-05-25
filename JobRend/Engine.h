#pragma once
#include "AbstractRenderer.h"
#include "EntityContainer.h"
class Engine
{
public:
	static AbstractRenderer* Renderer()
	{
		return renderer;
	}
	static void SetRender(AbstractRenderer* a_renderer)
	{
		renderer = a_renderer;
	}
	static bool MainLoop();

private:
	static AbstractRenderer* renderer;
	static EntityContainer* cont;


};

