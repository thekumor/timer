#pragma once

#include "util.h"
#include "base.h"
#include "font.h"
#include "events.h"
#include <string>
#include <windows.h>

namespace tmr {

	class Control : public BaseClass
	{
	public:
		Control(const Vec2u& size, const Vec2u& position, const std::wstring& text, HINSTANCE instance, Control* parent);
		Control() = default;
		virtual ~Control() {};

		EventReceiver* GetReceiver();
		const std::wstring& GetText();
		HWND GetHandle();

		void Show();
		void Close();
		void SetPosition(const Vec2u& position); // ??
		void SetText(const std::wstring& text);
		void Center();
		void SetFont(Font& font);

	protected:
		Vec2u m_Size = 0;
		Vec2u m_Position = 0;
		Control* m_Parent = nullptr;
		EventReceiver m_Receiver = {};
		Font m_Font;
		std::wstring m_Text = L"";
		HWND m_Handle = 0;
		HINSTANCE m_Instance = 0;
	};

}