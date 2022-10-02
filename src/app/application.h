#pragma once

#include "util.h"
#include "window.h"
#include "base.h"
#include "button.h"
#include "font.h"
#include "static.h"
#include <string>
#include <windows.h>
#include <vector>
#include <memory>

namespace tmr {

	class Application : public BaseClass
	{
	public:
		Application(HINSTANCE instance);
		
		void InitWindow(const Vec2u& size, const std::wstring& title);
		void Run();
		template <typename T>
		std::shared_ptr<Control>& AddControl(const T& control, Font& font);

	private:
		Window m_Window = {};
		std::vector<std::shared_ptr<Control>> m_Controls = {};
		HINSTANCE m_Instance = 0;
	};

}