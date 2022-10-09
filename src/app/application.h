#pragma once

#include "util.h"
#include "window.h"
#include "base.h"
#include "button.h"
#include "font.h"
#include "static.h"
#include "global.h"
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
		T* AddControl(const Vec2u& size, const Vec2u& position, const std::wstring& text,
											 HINSTANCE instance, Control* parent, Font& font);

	private:
		Window m_Window = {};
		std::vector<Control> m_Controls = {};
		HINSTANCE m_Instance = 0;
	};

}