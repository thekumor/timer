#include "font.h"

namespace tmr {

	Font::Font(uint16_t size, const std::wstring& name)
		: m_Size(size), m_Name(name)
	{
		m_Handle = CreateFont(
			size, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE, name.c_str()
		);
		GetWinAPIError();
	}

	HFONT Font::GetHandle()
	{
		return m_Handle;
	}

}