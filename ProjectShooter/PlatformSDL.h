#pragma once
#include "Platform.h"
#include "GL/glew.h"
#include "SDL.h"
#include "Log.h"
class PlatformSDL : public Platform
{
private:
	SDL_Window * window;
	SDL_GLContext renderer;
	int windowMode{ 0 };
public:
	void init() override; //+1 punto cora :'v
	void draw();
	int inputOne() override;
	PlatformSDL();
	~PlatformSDL();
};

