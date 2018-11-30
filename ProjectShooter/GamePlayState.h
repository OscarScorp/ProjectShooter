#pragma once
#include "State.h"
#include "Log.h"
#include "Map.h"
class GamePlayState : public State
{
private:
	Map map;
public:
	void Init() override;
	void Update() override;
	void Draw() override;
	void Input() override;
	GamePlayState();
	~GamePlayState();
};

