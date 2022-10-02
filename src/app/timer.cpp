#include "application.h"
#include "util.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow)
{
	tmr::Application app(instance);
	app.InitWindow(tmr::Vec2u(420, 200), L"Timer");
	app.Run();
}