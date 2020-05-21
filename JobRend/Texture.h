#pragma once
#include "SDL.h"

class Texture {

public:

    Texture(SDL_Renderer* renderer, int width, int height);
    Texture(SDL_Renderer* renderer, SDL_Texture* texture);
    ~Texture();

    int GetWidth()
    {
        return mWidth;
    }

    int GetHeight()
    {
        return mHeight;
    }

    void free();

    void updateTexture(Uint32* pixels);

    void renderToScreen(SDL_Renderer* mainRenderer);

private:
    int mPitch;
    SDL_Texture* mTexture;
    
    int mWidth;
    int mHeight;

};
