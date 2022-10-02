#pragma once

#include "control.h"
#include "util.h"
#include <string>
#include <windows.h>

namespace tmr {

	class Window : public Control
	{
	public:
		Window(const Vec2u& size, const std::wstring& title, HINSTANCE instance, LRESULT(*procedure)(HWND, UINT, WPARAM, LPARAM));
		Window() = default;

		void Create(const Vec2u& size, const std::wstring& title, HINSTANCE instance, LRESULT(*procedure)(HWND, UINT, WPARAM, LPARAM));
		void TranslateMessages();

		static LRESULT s_Procedure(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		WNDCLASSEX m_Class = {};
		LRESULT(*m_Procedure)(HWND, UINT, WPARAM, LPARAM) = nullptr;
	};

}