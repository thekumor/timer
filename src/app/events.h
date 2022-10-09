#pragma once

#include "base.h"
#include <unordered_map>
#include <functional>
#include <vector>
#include <windows.h>

namespace tmr {

	enum class EventType
	{
		None = 0,
		Click = 1,
		Update = 2,
		Timer = 3,
	};

	struct EventData
	{
		EventType Type;
		HWND Handle;
		WPARAM WParam;
		LPARAM LParam;
		bool Specific = true;
	};

	class EventReceiver;

	class EventSource : public BaseClass
	{
	public:
		EventSource() = default;

		void CallEvent(EventType type, const EventData& data);
		void Hook(EventReceiver* receiver);

	private:
		std::vector<EventReceiver*> m_Receivers = {};
	};

	class EventReceiver : public BaseClass
	{
	public:
		EventReceiver() = default;

		HWND GetOwnerHandle();

		void Trigger(EventType type, const EventData& data);
		void AddCallback(EventType type, std::function<void(const EventData& data)> callback);
		void SetHandle(HWND handle);

	private:
		std::unordered_map<EventType, std::function<void(const EventData&)>> m_Callbacks = {};
		HWND m_OwnerHandle = 0;
	};

}