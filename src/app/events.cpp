#include "events.h"

namespace tmr {

	void EventReceiver::Trigger(EventType type, const EventData& data)
	{
		auto& callback = m_Callbacks[type];

		if (callback)
		{
			callback(data);
		}
	}

	void EventReceiver::AddCallback(EventType type, std::function<void(const EventData&)> callback)
	{
		m_Callbacks[type] = callback;
	}

	HWND EventReceiver::GetOwnerHandle()
	{
		return m_OwnerHandle;
	}

	void EventSource::CallEvent(EventType type, const EventData& data)
	{
		for (auto& k : m_Receivers)
		{
			HWND handle = (HWND)data.LParam;
			if (!data.Specific || k->GetOwnerHandle() == handle)
			{
				k->Trigger(type, data);
			}
		}
	}

	void EventSource::Hook(EventReceiver* receiver)
	{
		m_Receivers.emplace_back(receiver);
	}

	void EventReceiver::SetHandle(HWND handle)
	{
		m_OwnerHandle = handle;
	}

}