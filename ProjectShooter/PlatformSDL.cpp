#include "pch.h"
#include "PlatformSDL.h"
#include "SDL.h"
#include <iostream>
#include <string>

void PlatformSDL::init()
{
	setWidth(getWidth());
	setHeight(getHeight());

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	//Get window mode.
	switch (windowGet){
		case 1:
			windowMode = SDL_WINDOW_FULLSCREEN;
			break;
		case 0:
		default:
			windowMode = SDL_WINDOW_SHOWN;
			break;
	}

	window = SDL_CreateWindow(getName().c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), windowMode);
	if (window == nullptr) {
		Log::Write("CreateWindow");
		throw std::runtime_error("error");
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		Log::Write("CreateRenderer");
		throw std::runtime_error("error");
		return;
	}
}

int PlatformSDL::inputOne()
{
	/*SDL_EVENT e;
	SD_PollEvent(&e);
	const Uinit8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		return 0;*/

	return 0;
}

PlatformSDL::PlatformSDL()
{
}

PlatformSDL::~PlatformSDL()
{
}
