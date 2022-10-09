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
		Button* button = AddControl<Button>(Vec2u(200, 30), Vec2u(100, 100), L"Start", m_Instance, &m_Window, defaultFont);
		Static* label = AddControl<Static>(Vec2u(200, 30), Vec2u(100, 50), L"0:00", m_Instance, &m_Window, defaultFont);

		EventReceiver* buttonReceiver = button->GetReceiver();
		EventReceiver* labelReceiver = label->GetReceiver();

		uint16_t tick = 0;
		uint16_t minutes = 0, seconds = 0;
		labelReceiver->AddCallback(EventType::Timer, [&](const EventData& data)
								   {
									   tick++;
									   seconds++;

									   if (seconds == 60)
									   {
										   seconds = 0;
										   minutes++;
									   }

									   label->SetText(std::to_wstring(minutes) + L":" + (seconds < 10 ? L"0" : L"") + std::to_wstring(seconds));

								   });
		buttonReceiver->AddCallback(EventType::Click, [&](const EventData& data)
								   {
									   if (button->GetText() == L"Start")
									   {
										   SetTimer(
											   m_Window.GetHandle(),
											   1,
											   1000,
											   (TIMERPROC)0
										   );

										   button->SetText(L"Stop");
										   label->SetText(L"0:00");
										   minutes = 0;
										   seconds = 0;
										   tick = 0;
									   }
									   else
									   {
										   KillTimer(m_Window.GetHandle(), 1);
										   button->SetText(L"Start");
									   }
								   });

		// Main loop
		m_Window.TranslateMessages();
	}

	template <typename T>
	T* Application::AddControl(const Vec2u& size, const Vec2u& position, const std::wstring& text,
							   HINSTANCE instance, Control* parent, Font& font)
	{
		T* control = new T(size, position, text, instance, parent);

		control->SetFont(font);
		g_EventSource.Hook(control->GetReceiver());

		return control;
	}

}