#include "window.h"

namespace tmr {

	Window::Window(const Vec2u& size, const std::wstring& title, HINSTANCE instance, LRESULT(*procedure)(HWND, UINT, WPARAM, LPARAM))
	{
		Create(size, title, instance, procedure);
	}

	void Window::Create(const Vec2u& size, const std::wstring& title, HINSTANCE instance, LRESULT(*procedure)(HWND, UINT, WPARAM, LPARAM))
	{
		const wchar_t className[] = L"Timer Window";

		// Custom window class
		m_Class.cbSize = sizeof(WNDCLASSEX);
		m_Class.hInstance = instance;
		m_Class.lpszClassName = className;
		m_Class.lpfnWndProc = procedure;
		RegisterClassEx(&m_Class);
		GetWinAPIError();

		// Window handle
		m_Handle = CreateWindowEx(
			0,
			className,
			title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			size.x,
			size.y,
			0,
			0,
			instance,
			0
		);
		GetWinAPIError();
	}

	void Window::TranslateMessages()
	{
		MSG msg = {};

		while (GetMessage(&msg, 0, 0, 0))
		{
			EventData tickData{
				.Type = EventType::Update,
				.Handle = 0,
				.WParam = 0,
				.LParam = 0
			};
			g_EventSource.CallEvent(EventType::Update, tickData);

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT Window::s_Procedure(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		EventData evData{
			.Type = EventType::None,
			.Handle = handle,
			.WParam = wParam,
			.LParam = lParam
		};

		switch (msg)
		{
			case WM_COMMAND:
				evData.Type = EventType::Click;
				g_EventSource.CallEvent(EventType::Click, evData);
				break;

			case WM_CLOSE:
				PostQuitMessage(0);
				break;

			case WM_TIMER:
				switch (wParam)
				{
					case 1:
						evData.Specific = false;
						g_EventSource.CallEvent(EventType::Timer, evData);
						break;
				}
				break;

			case WM_PAINT:
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(handle, &ps);
				FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 5));

				EndPaint(handle, &ps);
				break;

		}

		return DefWindowProc(handle, msg, wParam, lParam);
	}

}