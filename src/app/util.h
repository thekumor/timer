#pragma once

#include "base.h"
#include <cstdint>
#include <windows.h>

namespace tmr {

	uint16_t GetWinAPIError();

	struct Vec2u : public BaseClass
	{
		Vec2u(uint16_t x, uint16_t y);
		Vec2u(int val);
		Vec2u() = default;

		Vec2u&& operator=(int val);

		uint16_t x, y;
	};

}