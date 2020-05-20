#include "ScreenStates.h"

ScreenStateEnum ScreenState::state;

ScreenStateEnum ScreenState::GetState()
{
	return state;
}

void ScreenState::SetState(ScreenStateEnum nState)
{
	state = nState;
}