#pragma once

#include "util.h"
#include "control.h"
#include <windows.h>

namespace tmr {

	class Static : public Control
	{
	public:
		Static(const Vec2u& size, const Vec2u& position, const std::wstring& text, HINSTANCE instance, Control* parent = nullptr);
		Static() = default;
	};

}