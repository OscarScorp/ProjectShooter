#pragma once
#include <vector>
#include "State.h"
#include "Log.h"
#include "Platform.h"
#include "PlatformSDL.h"
class GameStateManager
{
private:
	std::vector<State *> States;
	int index = 0;
	PlatformSDL * platform;
public:
	void GameLoop();
	void PushState(State * st);
	GameStateManager();
	~GameStateManager();
};

