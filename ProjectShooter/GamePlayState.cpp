#include "pch.h"
#include "GamePlayState.h"

void GamePlayState::Init()
{
	Log::Write("Current state: Init.");
}

void GamePlayState::Update()
{
	Log::Write("Current state: Update.");
}

void GamePlayState::Draw()
{
	Log::Write("Current state: Draw.");
}

void GamePlayState::Input()
{
	Log::Write("Current state: Input.");
}

GamePlayState::GamePlayState()
{
}

GamePlayState::~GamePlayState()
{
}
