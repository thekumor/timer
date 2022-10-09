#include "application.h"
#include "util.h"
#include "global.h"
#include "events.h"
#include <windows.h>

namespace tmr {

	EventSource g_EventSource = {};

}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow)
{
	tmr::Application app(instance);
	app.InitWindow(tmr::Vec2u(420, 200), L"Timer");
	app.Run();
}