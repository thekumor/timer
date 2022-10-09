#include "static.h"

namespace tmr {

	Static::Static(const Vec2u& size, const Vec2u& position, const std::wstring& text, HINSTANCE instance, Control* parent)
		: Control(size, position, text, instance, parent)
	{
		m_Handle = CreateWindow(
			L"static",
			text.c_str(),
			WS_VISIBLE | SS_CENTER | (parent ? WS_CHILD : 0),
			position.x,
			position.y,
			size.x,
			size.y,
			parent->GetHandle(),
			0,
			instance,
			0
		);
		GetWinAPIError();

		m_Receiver.SetHandle(m_Handle);
	}

}