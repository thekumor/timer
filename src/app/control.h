#pragma once

#include "util.h"
#include "base.h"
#include <string>
#include <windows.h>

namespace tmr {

	class Control : public BaseClass
	{
	public:
		Control() = default;
		virtual ~Control() {};

		void Show();
		void Close();

	protected:
		Vec2u m_Size = 0;
		Vec2u m_Position = 0;
		std::wstring m_Text = L"";
		HWND m_Handle = 0;
		HINSTANCE m_Instance = 0;
	};

}