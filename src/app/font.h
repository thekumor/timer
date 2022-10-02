#pragma once

#include "base.h"
#include "util.h"
#include <cstdint>
#include <string>
#include <windows.h>

namespace tmr {

	class Font : public BaseClass
	{
	public:
		Font(uint16_t size, const std::wstring& name);
		Font() = default;

		HFONT GetHandle();

	private:
		uint16_t m_Size = 0;
		std::wstring m_Name = L"";
		HFONT m_Handle = 0;
	};

}