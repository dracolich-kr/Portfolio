#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlString::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_CHAR, &mValue, mLength, &length);

		return ErrorResult::Success;
	}
}