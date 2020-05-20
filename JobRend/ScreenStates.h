#pragma once
enum class ScreenStateEnum
{
	RUN,
	STOP
};

class ScreenState
{
public:
	static ScreenStateEnum GetState();
	static void SetState(ScreenStateEnum state);
private:
	static ScreenStateEnum state;
};
