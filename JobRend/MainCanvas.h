#pragma once
#include "Texture.h"
class MainCanvas
{
public:
	MainCanvas();
	Uint32* GetGBuffer()
	{
		return gBuffer;
	}
	void Render();
private: 
	Texture* texture;
	Uint32* gBuffer;
};

