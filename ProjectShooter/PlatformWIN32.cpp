#include "pch.h"
#include "PlatformWIN32.h"
#include <Windows.h>
#include <tchar.h>			// Unicode support	.. we will use TCHAR rather than char	

LRESULT CALLBACK PlatformWIN32::OpenGLDemoHandler(HWND Wnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

	switch (Msg) {
	case WM_CREATE: {											// WM_CREATE MESSAGE

	}
					break;
	case WM_DESTROY: {											// WM_DESTROY MESSAGE
	}
					 break;
	case WM_COMMAND:
		break;
	case WM_PAINT: {											// WM_PAINT MESSAGE
		return 0;
	}
				   break;
	case WM_TIMER: {											// WM_TIMER MESSAGE
	}
				   break;
	case WM_WINDOWPOSCHANGED:									// WM_WINDOWPOSCHANGED
		break;
	case WM_ERASEBKGND:											// WM_ERASEBKGND MESSAGE
		return (FALSE);
	default: return DefWindowProc(Wnd, Msg, wParam, lParam);	// Default handler
	};// end switch case
	return 0;
};

void PlatformWIN32::init()
{
	RECT R;
	HWND Wnd;
	WNDCLASSEX WndClass;
	const TCHAR* AppClassName = _T("Project Shooter");

	memset(&WndClass, 0, sizeof(WNDCLASSEX));						// Clear the class record
	WndClass.cbSize = sizeof(WNDCLASSEX);							// Size of this record
	WndClass.style = CS_OWNDC;										// Class styles
	WndClass.lpfnWndProc = OpenGLDemoHandler;						// Handler for this class
	WndClass.cbClsExtra = 0;										// No extra class data
	WndClass.cbWndExtra = 0;										// No extra window data
	WndClass.hInstance = GetModuleHandle(NULL);						// This instance
	WndClass.hIcon = LoadIcon(0, IDI_APPLICATION);					// Set icon
	WndClass.hCursor = LoadCursor(0, IDC_ARROW);					// Set cursor
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// Set background brush
	WndClass.lpszMenuName = NULL;									// No menu yet
	WndClass.lpszClassName = AppClassName;							// Set class name
	RegisterClassEx(&WndClass);										// Register the class
	GetClientRect(GetDesktopWindow(), &R);							// Get desktop area					
	
	/*
	Wnd = CreateWindowEx(0, AppClassName, _T("OpenGL Demo Program"),
		WS_VISIBLE | WS_OVERLAPPEDWINDOW, R.left + 50, R.top + 50,
		R.right - R.left - 100, R.bottom - R.top - 100,
		0, 0, 0, NULL);
		*/
	Wnd = CreateWindowEx(0, AppClassName, _T("OpenGL Demo Program"),
		WS_VISIBLE | WS_OVERLAPPEDWINDOW, 0, 0,
		600, 400,
		0, 0, 0, NULL);
	
	return;
}

int PlatformWIN32::inputOne()
{
	return 0;
}

void PlatformWIN32::winMessage()
{
	MSG Msg;
	while (GetMessage(&Msg, 0, 0, 0)) {								// Get messages
		TranslateMessage(&Msg);										// Translate each message
		DispatchMessage(&Msg);										// Dispatch each message
	};
	return;
}

PlatformWIN32::PlatformWIN32()
{
}


PlatformWIN32::~PlatformWIN32()
{
}
