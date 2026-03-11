#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult Query::Initalize(SharedSession session)
	{
		mSession = std::static_pointer_cast<DataBase::ODBC::Session>(session);

		SqlReturn result = SQLAllocHandle(SQL_HANDLE_STMT, mSession->GetDBC(), &mHandleStmt);

		if (result != SQL_SUCCESS &&
			result != SQL_SUCCESS_WITH_INFO)
			return ErrorResult::InitalizeFailed;

		return ErrorResult::Success;
	}

	ErrorResult Query::Release()
	{
		SQLFreeHandle(SQL_HANDLE_STMT, mHandleStmt);

		return ErrorResult::Success;
	}

	ErrorResult Query::AddResult(SharedResult result)
	{
		mResults.push_back(result);

		return ErrorResult::Success;
	}

	ErrorResult Query::Execute()
	{
		ErrorResult result = mCommand->Prepare();
		if (result != ErrorResult::Success)
			return result;

		SqlReturn sql_result = SQLExecute(mHandleStmt);

		if (sql_result != SQL_SUCCESS && sql_result != SQL_SUCCESS_WITH_INFO)
		{
			SQLSMALLINT iRec = 0;
			SQLINTEGER  iError;
			thread_local WCHAR wszMessage[1000];
			thread_local WCHAR wszState[SQL_SQLSTATE_SIZE + 1];

			if (sql_result == SQL_INVALID_HANDLE)
			{
				fwprintf(stderr, L"Invalid handle!\n");
				return ErrorResult::Failed;
			}

			while (SQLGetDiagRec(SQL_HANDLE_STMT,
				GetStmt(),
				++iRec,
				wszState,
				&iError,
				wszMessage,
				(SQLSMALLINT)(sizeof(wszMessage) / sizeof(WCHAR)),
				(SQLSMALLINT*)NULL) == SQL_SUCCESS)
			{
				// Hide data truncated..
				if (wcsncmp(wszState, L"01004", 5))
				{
					fwprintf(stderr, L"[%5.5s] %s (%d)\n", wszState, wszMessage, iError);
				}
			}

			return ErrorResult::Failed;
		}

		for(auto iter : mResults)
		{
			result = iter->onResult();
			if (result != ErrorResult::Success)
				return result;

			sql_result = SQLMoreResults(mHandleStmt);
			if (sql_result == SQL_NO_DATA)
				break;
		}

		return ErrorResult::Success;
	}

}