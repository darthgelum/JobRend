#pragma once
enum class ScreenStateEnum
{
	RUN,
	STOP
};

class ScreenState
{
public:
	static ScreenStateEnum state;
	static ScreenStateEnum GetState();
	static void SetState(ScreenStateEnum state);
};
