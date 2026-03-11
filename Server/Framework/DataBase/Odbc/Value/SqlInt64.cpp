#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlInt64::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_SBIGINT, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}