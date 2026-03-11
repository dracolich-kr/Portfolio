#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlUInt64::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_UBIGINT, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}