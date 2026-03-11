#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlDateTime::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_TYPE_TIMESTAMP, &mValue, sizeof(SQL_TIMESTAMP_STRUCT), &length);

		return ErrorResult::Success;
	}

	DateTime SqlDateTime::GetValue()
	{
		time_t _time;
		tm _tm;
		_tm.tm_year = mValue.year - 1900;
		_tm.tm_mon = mValue.month - 1;
		_tm.tm_hour = mValue.hour;
		_tm.tm_min = mValue.minute;
		_tm.tm_sec = mValue.second;
		mValue.fraction;

		return DateTime(_time, _tm);
	}
}