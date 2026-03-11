#pragma once

/// <summary>
/// DateTime 시간 체크용.
/// </summary>
class TimeSpan
{
public:
	TimeSpan() {}
	virtual ~TimeSpan() {}

	Year GetTotalYear();
	Month GetTotalMonth();
	Day GetTotalDay();
	Hour GetTotalHour();
	Minute GetTotalMinute();
	Second GetTotalSecond();

private:

};