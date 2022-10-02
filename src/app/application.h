#pragma once

#include "util.h"
#include "window.h"
#include "base.h"
#include <string>
#include <windows.h>

namespace tmr {

	class Application : public BaseClass
	{
	public:
		Application(HINSTANCE instance);
		
		void InitWindow(const Vec2u& size, const std::wstring& title);
		void Run();

	private:
		Window m_Window = {};
		HINSTANCE m_Instance = 0;
	};

}