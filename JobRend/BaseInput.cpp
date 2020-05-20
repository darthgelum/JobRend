#include "BaseInput.h"
#include "ScreenStates.h"
void BaseInputEntity::OnEvent(SDL_Event e)
{
    if( (e.type == SDL_QUIT) || (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE))
        ScreenState::SetState(ScreenStateEnum::STOP);
}