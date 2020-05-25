#include "Texture.h"
Texture::Texture(SDL_Renderer* renderer, int width, int height) {
    mWidth = width;
    mHeight = height;
    mPitch = width * sizeof(Uint32);
    mTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC, mWidth, mHeight);
    SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);
}

Texture::Texture(SDL_Renderer* renderer, SDL_Texture* texture) {
    mTexture = texture;
    SDL_QueryTexture(texture,NULL,NULL, &mWidth, &mHeight);
    mPitch = mWidth * sizeof(Uint32);
    SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);
}

Texture::~Texture() {
    free();
}

void Texture::free() {
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mWidth = 0;
        mHeight = 0;
        mPitch = 0;
    }
}


void Texture::updateTexture(Uint32* pixels) {
    SDL_UpdateTexture(mTexture, NULL, pixels, mPitch);
}

void Texture::renderToScreen(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, mTexture, NULL, NULL);
}