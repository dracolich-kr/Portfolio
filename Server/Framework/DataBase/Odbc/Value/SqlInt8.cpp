#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlInt8::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_STINYINT, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}