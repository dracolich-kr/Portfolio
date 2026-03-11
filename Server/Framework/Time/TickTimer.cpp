#include <Pch.h>
using namespace std::chrono;

TickTimer::TickTimer()
	: misActivte(false)
{
	Reset(); 
}

TickTimer::TickTimer(DateTime time)
	: misActivte(false)
{
	m_time = system_clock::from_time_t(time.GetTime());
}

void TickTimer::Reset()
{
	m_time = system_clock::now();
}

bool TickTimer::isExpired()
{
	IF_RETURN(false == misActivte, true);

	auto now_time = system_clock::now();
	milliseconds milli = duration_cast<milliseconds>(now_time - m_time);

	IF_RETURN(milli.count() < 0, false);

	return true;
}

void TickTimer::Activate(Int32 millisecond)
{
	misActivte = true;

	m_time = system_clock::now() + milliseconds(millisecond);
}

void TickTimer::DeActivate()
{
	Reset();
	misActivte = false;
}