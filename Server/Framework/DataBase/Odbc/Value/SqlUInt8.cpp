#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult SqlUInt8::onBindCol(SqlHandleStmt stmt)
	{
		static SqlLen length = 0;
		SqlReturn result = SQLBindCol(stmt, mColumnIndex, SQL_C_UTINYINT, &mValue, sizeof(mValue), &length);

		return ErrorResult::Success;
	}
}