#include "pch.h"
#include "GameStateManager.h"

void GameStateManager::GameLoop()
{
	try {
		while (true)
		{
			States[index]->Input();
			States[index]->Update();
			States[index]->Draw();
		}
	}
	catch(...){
		Log::Write("[ERROR] In function (GameLoop): No state");
	}
}

void GameStateManager::PushState(State * st)
{
	if (st != nullptr)
		States.push_back(st);
}

GameStateManager::GameStateManager()
{
	platform = new PlatformSDL();
	platform->readConfig();
	platform->init();
}

GameStateManager::~GameStateManager()
{
}
