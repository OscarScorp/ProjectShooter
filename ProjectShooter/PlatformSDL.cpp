#include "pch.h"
#include "PlatformSDL.h"
#include <iostream>
#include <string>

void PlatformSDL::Init(int WIDTH, int HEIGHT, int flags)
{
	setWidth(WIDTH);
	setHeight(HEIGHT);

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	window = SDL_CreateWindow(getName().c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), SDL_WINDOW_SHOWN);
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

PlatformSDL::PlatformSDL()
{
}

PlatformSDL::~PlatformSDL()
{
}
