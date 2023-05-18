#include <Pch.h>

TickTimer::TickTimer(DateTime time)
{
	m_time = std::chrono::system_clock::from_time_t(time.GetTime());
}

void TickTimer::Reset()
{
	m_time = std::chrono::system_clock::now();
}
