#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult Result::onResult()
	{
		ErrorResult result = Bind();
		if (result != ErrorResult::Success)
			return result;

		SqlReturn sql_result = SQL_SUCCESS;

		while (SQL_SUCCESS == sql_result ||
			SQL_SUCCESS_WITH_INFO == sql_result)
		{
			sql_result = SQLFetch(mQuery->GetStmt());

			if (sql_result == SQL_NO_DATA)
				return ErrorResult::Success;
			else if (sql_result == SQL_ERROR)
				return ErrorResult::Failed;

			result = Fetch();
			if (result != ErrorResult::Success)
				return result;
		}

		return ErrorResult::Success;
	}

}