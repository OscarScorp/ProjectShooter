#pragma once
#include "Platform.h"
#include <Windows.h>

class PlatformWIN32 : public Platform
{
private:
	static LRESULT CALLBACK OpenGLDemoHandler(HWND Wnd, UINT Msg, WPARAM wParam, LPARAM lParam);
public:
	void init() override;
	int inputOne() override;
	void winMessage();
	PlatformWIN32();
	~PlatformWIN32();
};

