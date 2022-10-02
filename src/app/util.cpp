#include "util.h"

namespace tmr {

	Vec2u::Vec2u(uint16_t x, uint16_t y)
		: x(x), y(y)
	{
	}

	Vec2u::Vec2u(int val)
		: x(val), y(val)
	{
	}

	Vec2u&& Vec2u::operator=(int val)
	{
		return {0, 0};
	}

	uint16_t GetWinAPIError()
	{
		uint16_t code = GetLastError();

		if (code)
		{
			// Attempts to translate the error.
			LPWSTR message = 0;
			size_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
										 0, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&message, 0, nullptr);
			MessageBox(nullptr, message, L"WinAPI", IDOK);
			LocalFree(message);
		}

		return code;
	}

}