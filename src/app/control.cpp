#include "control.h"

namespace tmr {
	
	Control::Control(const Vec2u& size, const Vec2u& position, const std::wstring& text, HINSTANCE instance, Control* parent)
		: m_Size(size), m_Position(position), m_Text(text), m_Instance(instance), m_Parent(parent)
	{
	}

	EventReceiver* Control::GetReceiver()
	{
		return &m_Receiver;
	}

	const std::wstring& Control::GetText()
	{
		return m_Text;
	}

	HWND Control::GetHandle()
	{
		return m_Handle;
	}

	void Control::Show()
	{
		ShowWindow(m_Handle, SW_SHOW);
	}

	void Control::Close()
	{
		CloseWindow(m_Handle);
	}

	void Control::SetPosition(const Vec2u& position)
	{
		m_Position = position;
		SetWindowPos(m_Handle, 0, position.x, position.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER); // SWP_NOACTIVATE
	}

	void Control::SetText(const std::wstring& text)
	{
		m_Text = text;
		SetWindowText(m_Handle, text.c_str());
	}

	void Control::Center()
	{
		Vec2u position = 0;
		
		RECT rc;
		GetWindowRect(m_Handle, &rc);

		uint16_t x = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
		uint16_t y = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;
		
		position.x = x;
		position.y = y;

		SetPosition(position);
	}

	void Control::SetFont(Font& font)
	{
		m_Font = font;
		SendMessage(m_Handle, WM_SETFONT, (WPARAM)font.GetHandle(), 0);
	}

}