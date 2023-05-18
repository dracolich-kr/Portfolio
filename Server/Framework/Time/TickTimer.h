#pragma once

class DateTime;

class TickTimer
{
public:
	TickTimer() { Reset(); }
	TickTimer(DateTime time);
	virtual ~TickTimer() {}

	void Reset();

private:
	std::chrono::system_clock::time_point m_time;

};
