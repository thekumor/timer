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
		m_Window.Center();

		Font defaultFont(24, L"Segoe UI");

		// Controls
		AddControl<Button>(Button(Vec2u(200, 30), Vec2u(100, 100), L"Start", m_Instance, &m_Window), defaultFont);
		AddControl<Static>(Static(Vec2u(200, 30), Vec2u(100, 50), L"00:00:00", m_Instance, &m_Window), defaultFont);

		m_Window.TranslateMessages();
	}

	template <typename T>
	std::shared_ptr<Control>& Application::AddControl(const T& control, Font & font)
	{
		std::shared_ptr<T> newControl = std::make_shared<T>(control);
		std::shared_ptr<Control> converted = newControl;
		converted->SetFont(font);

		return m_Controls.emplace_back(converted);
	}

}