#pragma once
#include "Platform.h"
#include "SDL.h"
class PlatformSDL : public Platform
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
public:
	void Init(int WIDTH, int HEIGHT, int flags) override; //+1 punto cora :'v
	PlatformSDL();
	~PlatformSDL();
};

