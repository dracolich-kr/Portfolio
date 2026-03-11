#pragma once



class DateTime
{
public:
	static DateTime GetNow();
	static DateTime GetUtcNow();

	DateTime() {}
	DateTime(time_t& _time, tm& _tm) { m_time = std::move(_time); m_tm = std::move(_tm); }
	virtual ~DateTime() {}

	void Reset();

	void AddYear(const Year year);
	void AddMonth(const Month month);
	void AddDay(const Day day);
	void AddHour(const Hour hour);
	void AddMinute(const Minute minute);
	void AddSecond(const Second second);

	Year GetYear() { return m_tm.tm_year + 1900; }
	Month GetMonth() { return m_tm.tm_mon + 1; }
	Day GetDay() { return m_tm.tm_mday; }
	Hour GetHour() { return m_tm.tm_hour; }
	Minute GetMinute() { return m_tm.tm_min; }
	Second GetSecond() { return m_tm.tm_sec; }

	__time64_t& GetTime() { return m_time; }
	tm& GetTm() { return m_tm; }

	std::shared_ptr<SQL_TIMESTAMP_STRUCT> GetSqlTimeStamp();

private:
	void CalcTime();

private:
	__time64_t m_time = 0;
	tm m_tm = { 0, };
};