#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlDouble::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_DOUBLE, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}