#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlFloat::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_FLOAT, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}