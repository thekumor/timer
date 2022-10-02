#pragma once

#include "util.h"
#include "control.h"
#include <string>
#include <windows.h>

namespace tmr {

	class Button : public Control
	{
	public:
		Button(const Vec2u& size, const Vec2u& position, const std::wstring& text, HINSTANCE instance, Control* parent = nullptr);
		Button() = default;
	};

}