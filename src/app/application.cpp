#include "application.h"

namespace tmr {

	Application::Application(HINSTANCE instance)
		: m_Instance(instance)
	{
	}

	void Application::InitWindow(const Vec2u& size, const std::wstring& title)
	{
		m_Window.Create(size, title, m_Instance, Window::s_Procedure);
	}

	void Application::Run()
	{
		m_Window.Show();

		while (true) //TODO: app running
		{
			m_Window.TranslateMessages();
		}
	}

}