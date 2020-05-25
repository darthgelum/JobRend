#include "Engine.h"
#include "ScreenStates.h"
#include "SDLSoftwareRenderer.h"

AbstractRenderer* Engine::renderer;
EntityContainer* Engine::cont;
bool Engine::MainLoop()
{
    cont = new EntityContainer();
    ScreenState::SetState(ScreenStateEnum::RUN);
    for (Entity* e : cont->GetAll())
    {
        e->Start();
    }

    while (ScreenState::GetState() == ScreenStateEnum::RUN) {

        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            for (Entity* en : cont->GetAll())
            {
                en->OnEvent(e);
            }
        }
        renderer->ClearScreen();
        for (Entity* e : cont->GetAll())
        {
            e->Update();
        }
        renderer->RenderToScreen();

    }

    delete cont, renderer;
    return false;
};
