#pragma once

class DateTime;

class TickTimer
{
public:
	TickTimer();
	TickTimer(DateTime time);
	virtual ~TickTimer() {}

	void Reset();

	void Activate(Int32 millisecond);
	void DeActivate();

	bool isExpired();

private:
	std::chrono::system_clock::time_point m_time;
	bool misActivte;

};
