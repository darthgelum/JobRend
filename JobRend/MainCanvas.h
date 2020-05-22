#pragma once
#include "Texture.h"
#include "Vector2.h"
#include "Vector3.h"
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
	
	int GetPitch()
	{
		return texture->GetPitch();
	}

	Vector2 CenterPoint()
	{
		return center;
	}
	void DrawLine(Vector3 vertex1, Vector3 vertex2, Uint32 color);

	Uint32* SetPixelColor(Uint32 color, int x, int y);

	Uint32* SetPixelColor(Uint32 color, Uint32* pixel);

	void Render();

	Vector2 GetCoordsOfPixel(int number);

	Uint32 CColor(int r, int g, int b, int a = 0xFF);

private: 
	int convertCoordinates(int x, int y);
	Texture* texture;
	Uint32* gBuffer;
	SDL_PixelFormat* mappingFormat;
	Vector2 center = Vector2(0,0);
};

