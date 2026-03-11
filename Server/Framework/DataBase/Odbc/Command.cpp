#include <Pch.h>

namespace DataBase::ODBC
{
	ErrorResult Command::Init(DefWString message)
	{
		SqlReturn result = SQLPrepareW(mQuery->GetStmt(), (SQLWCHAR*)message.c_str(), SQL_NTS);

		return ErrorResult::Success;
	}

	ErrorResult Command::Release()
	{
		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Int64 value)
	{
		static SqlLen length = sizeof(Int64);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_SBIGINT, SQL_BIGINT, 0, 0, &value, length, nullptr);
		if (result != SQL_SUCCESS && result != SQL_SUCCESS_WITH_INFO) 
		{
			//return GetOdbcError(henv, hdbc, hstmt, NULL, true);
		}

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, UInt64 value)
	{
		static SqlLen length = sizeof(UInt64);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_UBIGINT, SQL_BIGINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Int32 value)
	{
		static SqlLen length = sizeof(Int32);
		static SqlLen lnd = 0;
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_SLONG, SQL_INTEGER, 0, 0, &value, length, &lnd);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, UInt32 value)
	{
		static SqlLen length = sizeof(UInt32);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_ULONG, SQL_INTEGER, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Int16 value)
	{
		static SqlLen length = sizeof(Int16);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_SSHORT, SQL_SMALLINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, UInt16 value)
	{
		static SqlLen length = sizeof(UInt16);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_USHORT, SQL_SMALLINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Int8 value)
	{
		static SqlLen length = sizeof(Int8);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_STINYINT, SQL_TINYINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, UInt8 value)
	{
		static SqlLen length = sizeof(UInt8);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Char value)
	{
		static SqlLen length = sizeof(Char);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_UTINYINT, SQL_TINYINT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Float value)
	{
		static SqlLen length = sizeof(Float);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_FLOAT, SQL_FLOAT, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, Double value)
	{
		static SqlLen length = sizeof(Double);
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_DOUBLE, SQL_DOUBLE, 0, 0, &value, length, nullptr);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, DefString value)
	{
		static SqlLen length = SQL_NTS;
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_CHAR, SQL_VARCHAR, value.size(), 0, (void*)value.c_str(), value.length(), &length);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, DefWString value)
	{
		static SqlLen length = SQL_NTS;
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_WCHAR, SQL_WVARCHAR, value.size(), 0, (void*)value.c_str(), value.length(), &length);

		return ErrorResult::Success;
	}

	ErrorResult Command::BindParam(SqlInputType type, DateTime value)
	{
		static SqlLen length = SQL_NTS;
		SqlTimeStampStruct date_struct;
		
		SqlReturn result = SQLBindParameter(mQuery->GetStmt(), mLength++, type, SQL_C_TIMESTAMP, SQL_TYPE_TIMESTAMP, 27, 7, &date_struct, 0, &length);

		return ErrorResult::Success;
	}

	ErrorResult Command::checkResult(SqlReturn result)
	{
		ErrorResult error_result = ErrorResult::Success;
		SQLSMALLINT iRec = 0;
		//SQLINTEGER  error_no;
		thread_local WCHAR       message[1024];
		thread_local WCHAR       state[SQL_SQLSTATE_SIZE + 1];

		switch (result)
		{
			case SQL_SUCCESS:
				error_result = ErrorResult::Success;
				break;
			case SQL_SUCCESS_WITH_INFO:
			case SQL_ERROR:
				//SQLGetDiagRec(SQL_HANDLE_STMT, );
				break;
			case SQL_INVALID_HANDLE:
				error_result = ErrorResult::SocketBindFailed;
				break;
		}

		return error_result;
	}
}