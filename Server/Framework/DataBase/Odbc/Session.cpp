#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult Session::Init()
	{
		SqlReturn result = SQL_SUCCESS;

		// Environment Handle 할당
		result = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &mHandleEnv);

		if (result != SQL_SUCCESS &&
			result != SQL_SUCCESS_WITH_INFO)
		{
			return ErrorResult::SocketAllocFailed;
		}

		// ODBC 버전 세팅
		result = SQLSetEnvAttr(mHandleEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

		// DBC Handle 할당
		result = SQLAllocHandle(SQL_HANDLE_DBC, mHandleEnv, &mHandleDbc);

		if (result != SQL_SUCCESS &&
			result != SQL_SUCCESS_WITH_INFO)
		{
			GetError(result);
			return ErrorResult::SocketAllocFailed;
		}

		// 5초 동안 연결 시도
		Int64 connect_second = 5;
		result = SQLSetConnectAttr(mHandleDbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)connect_second, 0);
		if (result != SQL_SUCCESS &&
			result != SQL_SUCCESS_WITH_INFO)
		{
			return ErrorResult::SocketAllocFailed;
		}

		return ErrorResult::Success;
	}

	ErrorResult Session::Release()
	{
		SQLFreeHandle(SQL_HANDLE_DBC, mHandleDbc);
		SQLFreeHandle(SQL_HANDLE_ENV, mHandleEnv);

		return ErrorResult::Success;
	}

	ErrorResult Session::Connect(DefWString db_name, DefWString ip, Port port, DefWString user, DefWString password)
	{
		SqlReturn result = SQL_SUCCESS;

		SQLWCHAR buffer[256] = { 0, };
		SQLWCHAR output[1024 + 1] = { 0, };
		SQLSMALLINT outlength = 0;

		mDbName = db_name;
		mHost = ip;
		mPort = port;
		mUser = user;
		mPassword = password;

		swprintf_s(buffer, L"DRIVER={SQL Server};SERVER=%s,%d;DATABASE=%s;UID=%s;PWD=%s;", ip.c_str(), port, db_name.c_str(), user.c_str(), password.c_str());

		result = SQLDriverConnect(mHandleDbc, nullptr, buffer, SQL_NTS, output, 1024, &outlength, SQL_DRIVER_NOPROMPT);
		if ((result != SQL_SUCCESS) && (result != SQL_SUCCESS_WITH_INFO))
		{
			return ErrorResult::Failed;
		}

		result = ::SQLSetConnectAttr(mHandleDbc, SQL_ATTR_AUTOCOMMIT, reinterpret_cast<SQLPOINTER>(SQL_AUTOCOMMIT_ON), SQL_IS_INTEGER);

		return ErrorResult::Success;
	}

	ErrorResult Session::Connect(DefWString file_name)
	{
		mFileName = file_name;

		return ErrorResult::Success;
	}

	ErrorResult Session::ReConnect()
	{

		return ErrorResult::Success;
	}

	ErrorResult Session::Disconnect()
	{
		SqlReturn result = SQLDisconnect(mHandleDbc);

		return ErrorResult::Success;
	}

	// 왜 헤더를 못찾냐..
	//ErrorResult Session::SetTranslate(bool is_onoff)
	//{
	//	SqlReturn result = SQL_SUCCESS;
	//	if (is_onoff == true)
	//	{
	//		result = ::SQLSetConnectAttr(mHandleDbc, SQL_COPT_SS_TRANSLATE, reinterpret_cast<SQLPOINTER>(SQL_XL_ON), SQL_IS_INTEGER);
	//	}
	//	else
	//	{
	//		result = ::SQLSetConnectAttr(mHandleDbc, SQL_COPT_SS_TRANSLATE, reinterpret_cast<SQLPOINTER>(SQL_XL_OFF), SQL_IS_INTEGER);
	//	}
	//
	//	if ((result != SQL_SUCCESS) && (result != SQL_SUCCESS_WITH_INFO))
	//	{
	//		return ErrorResult::Failed;
	//	}
	//
	//	return ErrorResult::Success;
	//}

	ErrorResult Session::BeginTrans()
	{
		IF_RETURN(mTransactionMode == true, ErrorResult::Failed);

		SqlReturn result = SQLSetConnectAttr(mHandleDbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)SQL_AUTOCOMMIT_OFF, 0);

		mTransactionMode = true;

		return ErrorResult::Success;
	}

	ErrorResult Session::EndTrans(bool is_roll_back)
	{
		IF_RETURN(mTransactionMode == false, ErrorResult::Failed);

		SqlReturn result = ::SQLEndTran(SQL_HANDLE_DBC, mHandleDbc, (is_roll_back ? SQL_ROLLBACK : SQL_COMMIT));

		result = SQLSetConnectAttr(mHandleDbc, SQL_ATTR_AUTOCOMMIT, (SQLPOINTER)SQL_AUTOCOMMIT_ON, 0);

		mTransactionMode = false;

		return ErrorResult::Success;
	}

	ErrorResult Session::GetError(SqlReturn result)
	{
		if (result == SQL_ERROR)
		{
			SQLSMALLINT result = 0;
			SQLINTEGER iError;
			thread_local WCHAR message[1024];
			thread_local WCHAR wszState[SQL_SQLSTATE_SIZE + 1];

			if (result == SQL_INVALID_HANDLE)
			{
				fwprintf(stderr, L"Invalid handle!\n");
				return ErrorResult::Failed;
			}

			while (SQLGetDiagRec(SQL_HANDLE_ENV,
				mHandleEnv,
				++result,
				wszState,
				&iError,
				message,
				(SQLSMALLINT)(sizeof(message) / sizeof(WCHAR)),
				(SQLSMALLINT*)NULL) == SQL_SUCCESS)
			{
				// Hide data truncated..
				if (wcsncmp(wszState, L"01004", 5))
				{
					fwprintf(stderr, L"[%5.5s] %s (%d)\n", wszState, message, iError);
				}
			}

			return ErrorResult::Failed;
		}

		return ErrorResult::Success;
	}
}
