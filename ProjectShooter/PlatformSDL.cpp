#include "pch.h"
#include "PlatformSDL.h"
#include "SDL.h"
#include "GL/glew.h"
#include <iostream>
#include <string>

void PlatformSDL::draw()
{
	SDL_GL_SwapWindow(window);
	SDL_Delay(1);
}

void PlatformSDL::init()
{
	Platform::init();

	setWidth(getWidth());
	setHeight(getHeight());


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
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

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(getName().c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, getWidth(), getHeight(), windowMode | SDL_WINDOW_OPENGL);

	if (window == nullptr) {
		Log::Write("CreateWindow");
		throw std::runtime_error("error");
		return;
	}

	renderer = SDL_GL_CreateContext(window);

	if (renderer == nullptr) {
		Log::Write("CreateRenderer");
		throw std::runtime_error("error");
		return;
	}

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cout << "error init opengl";
	}

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

int PlatformSDL::inputOne()
{
	/*SDL_EVENT e;
	SD_PollEvent(&e);
	const Uinit8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		return 0;*/

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{

	}
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	return 0;
}

PlatformSDL::PlatformSDL()
{
}

PlatformSDL::~PlatformSDL()
{
}
