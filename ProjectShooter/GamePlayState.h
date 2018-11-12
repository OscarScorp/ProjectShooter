#pragma once
#include "State.h"
#include "Log.h"
class GamePlayState : public State
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Input() override;
	GamePlayState();
	~GamePlayState();
};

