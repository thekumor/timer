#include "control.h"

namespace tmr {

	void Control::Show()
	{
		ShowWindow(m_Handle, SW_SHOW);
	}

	void Control::Close()
	{
		CloseWindow(m_Handle);
	}

}