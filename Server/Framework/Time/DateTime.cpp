#include <Pch.h>

DateTime DateTime::GetNow()
{
	__time64_t _time = _time64(0);
	tm _tm;
	_localtime64_s(&_tm, &_time);

	return DateTime(_time, _tm);
}

DateTime DateTime::GetUtcNow()
{
	__time64_t _time = _time64(0);
	tm _tm;
	_gmtime64_s(&_tm, &_time);
	return DateTime(_time, _tm);
}

void DateTime::Reset()
{
	__time64_t _time = _time64(0);
	CalcTime();
}

void DateTime::AddYear(const Year year)
{
	m_tm.tm_year += year;
	CalcTime();
}

void DateTime::AddMonth(const Month month)
{
	m_tm.tm_mon += month;
	CalcTime();
}

void DateTime::AddDay(const Day day)
{
	m_tm.tm_mday += day;
	CalcTime();
}

void DateTime::AddHour(const Hour hour)
{
	m_tm.tm_hour += hour;
	CalcTime();
}

void DateTime::AddMinute(const Minute minute)
{
	m_tm.tm_min += minute;
	CalcTime();
}

void DateTime::AddSecond(const Second second)
{
	m_tm.tm_sec += second;
	CalcTime();
}

void DateTime::CalcTime()
{
	m_time = _mktime64(&m_tm);
}

std::shared_ptr<SQL_TIMESTAMP_STRUCT> DateTime::GetSqlTimeStamp()
{
	std::shared_ptr<SQL_TIMESTAMP_STRUCT> temp = MakeShared<SQL_TIMESTAMP_STRUCT>();

	temp->year = GetYear();
	temp->month = GetMonth();
	temp->day = GetDay();
	temp->hour = GetHour();
	temp->minute = GetMinute();
	temp->second = GetSecond();

	return temp;
}