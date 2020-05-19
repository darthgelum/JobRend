#include "Entity.h"
#include "ScreenState.h"
class GlobalControlEntity : Entity
{
public:
	void OnEvent(SDL_Event e) override {
        if (e.type == SDL_QUIT)
            ScreenState = ScreenState::Stop;
        else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
            ScreenState = ScreenState::Stop;
	}
};
