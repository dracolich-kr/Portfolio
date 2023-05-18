#pragma once

namespace DataBase::ODBC
{
	static class Error
	{
	public:
		static bool getError(SqlHandleEnv hEnv, SqlHandleDbc hdbc, SqlHandleStmt stmt);

	};

};