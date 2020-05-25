#include "SDLSoftwareRenderer.h"
#include <stdexcept>


void SDLSoftwareRenderer::init()
{
    int w = GetWidth();
    int h = GetHeight();
    mappingFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
		"JobRend",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w, h, SDL_WINDOW_OPENGL
	);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		throw std::invalid_argument("Window initialisation error");
	}
	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	surface = SDL_GetWindowSurface(window);
    SDL_QueryTexture(mainCanvas, NULL, NULL, &w, &h);
    mainCanvas = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC, w, h);
    SDL_SetTextureBlendMode(mainCanvas, SDL_BLENDMODE_BLEND);
    //delete(&w);
    //delete(&h);
}

Uint32 SDLSoftwareRenderer::ConvertColor(Color color)
{
    return SDL_MapRGBA(mappingFormat, color.R, color.G, color.B, color.A);
}

SDLSoftwareRenderer::~SDLSoftwareRenderer()
{
    if (mainCanvas != NULL) {
        SDL_DestroyTexture(mainCanvas);
    }
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}


void SDLSoftwareRenderer::DrawModel(Model* model)
{
}

void SDLSoftwareRenderer::DrawLine(Vector3 start, Vector3 end, Color color)
{
    // Coord + centerization (center on x, 2/3 on y)
    int x0 = start.x + GetWidth()/2;
    int y0 = -start.y + GetHeight() / 2;
    int x1 = end.x + GetWidth() / 2;
    int y1 = -end.y + GetHeight() / 2;
    // Bresenheim algo
    const int deltaX = abs(x1 - x0);
    const int deltaY = abs(y1 - y0);
    const int signX = x0 < x1 ? 1 : -1;
    const int signY = y0 < y1 ? 1 : -1;

    int error = deltaX - deltaY;
    int error2 = 0;
    //last point
    SetPixelColor(x1, y1, color);
    while (x0 != x1 || y0 != y1)
    {
        SetPixelColor(x0, y0, color);
        error2 = error << 1;
        //
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x0 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y0 += signY;
        }
    }
}

void SDLSoftwareRenderer::SetPixelColor(int x, int y, Color color)
{
    if (x < 0 || y < 0 || x>GetWidth() || y>GetHeight())
    {
        return;
    }
    int pixelNumber = ((y * GetHeight()) + x);

    gBuffer[pixelNumber] = ConvertColor(color);
}

void SDLSoftwareRenderer::ColorTriangle(Vector3 triangle, Color color)
{
}

void SDLSoftwareRenderer::ClearScreen()
{
	SDL_RenderClear(sdl_renderer);
	memset(gBuffer, 0, pixelsCount * sizeof(Uint32));
}

void SDLSoftwareRenderer::RenderToScreen()
{
    SDL_UpdateTexture(mainCanvas, NULL, gBuffer, GetWidth()*sizeof(Uint32));

    SDL_RenderCopy(sdl_renderer, mainCanvas, NULL, NULL);
    SDL_RenderPresent(sdl_renderer);
}
