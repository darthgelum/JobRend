#pragma once
#include "AbstractRenderer.h"
#include <SDL.h>
#include "Color.h"
class SDLSoftwareRenderer : public AbstractRenderer {
private:
	void init();
	Uint32 ConvertColor(Color color);
	SDL_Window* window;
	SDL_Renderer* sdl_renderer;
	SDL_Surface* surface;
	SDL_Texture* mainCanvas;
	Vector2 center = Vector2(0,0);
	Uint32* gBuffer;
	int pixelsCount;
	int pitch;
public:
	SDL_PixelFormat* mappingFormat;
	SDLSoftwareRenderer(int width, int height) : AbstractRenderer(width, height) {
		init();

		pixelsCount = width * height;
		gBuffer = new Uint32[pixelsCount+1];
		center = Vector2(width / 2, -height / 2);
		pitch = width * sizeof(Uint32);
	};
	 ~SDLSoftwareRenderer();
	 
	 void DrawModel(Model* model) override;
	 void DrawLine(Vector3 start, Vector3 end, Color color) override;
	 void SetPixelColor(int x, int y, Color color) override;
	 void ColorTriangle(Vector3 triangle, Color color) override;
	 void ClearScreen() override;
	 void RenderToScreen() override;
};