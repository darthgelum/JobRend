#pragma once
#include "Texture.h"
#include "Vector2.h"
class MainCanvas
{
public:
	MainCanvas();
	Uint32* GetGBuffer()
	{
		return gBuffer;
	}

	int GetWidth()
	{
		return texture->GetWidth();
	}

	int GetHeight()
	{
		return texture->GetHeight();
	}
	void SetPixelColor(Uint32 color, int x, int y);

	void Render();

	Vector2 GetCoordsOfPixel(int number);

	static Uint32 CColor(int r, int g, int b, int a = 0xFF);

private: 
	int convertCoordinates(int x, int y);
	Texture* texture;
	Uint32* gBuffer;
};

