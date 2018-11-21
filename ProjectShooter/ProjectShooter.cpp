// ProjectShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include "State.h"
#include "GamePlayState.h"
#include "GameStateManager.h"

#include <iostream>


int main(int argc, char *argv[])
{
	State * gamePlay = new GamePlayState();

	GameStateManager * stateManager = new GameStateManager();
	stateManager->PushState(gamePlay);
	stateManager->GameLoop(); //Dentro el init.
	
	system("pause");
	return 0;
}
