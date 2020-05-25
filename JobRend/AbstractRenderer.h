#pragma once
#include "Model.h"
#include "Canvas.h"
#include "Color.h"
class AbstractRenderer
{
private:
	 int screenHeight=0;
	 int screenWidth=0;
public:
	explicit AbstractRenderer(int width, int height) {
		screenHeight = height;
		screenWidth = width;
	};
	 int GetWidth()
	{
		return screenWidth;
	}
	 int GetHeight()
	{
		return screenHeight;
	}
	virtual void DrawModel(Model* model) {};
	virtual void DrawLine(Vector3 start, Vector3 end, Color color) {};
	virtual void SetPixelColor(int x, int y, Color color) {};
	virtual void ColorTriangle(Vector3 triangle, Color color) {};
	virtual void RenderToScreen() {};
	virtual void ClearScreen() {};
};