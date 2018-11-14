#pragma once
#include "Platform.h"
#include "SDL.h"
#include "Log.h"
class PlatformSDL : public Platform
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	int windowMode{ 0 };
public:
	void init() override; //+1 punto cora :'v
	int inputOne() override;
	PlatformSDL();
	~PlatformSDL();
};

