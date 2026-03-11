#include <Pch.h>

namespace DataBase::MySql
{
	ErrorResult Session::Connect(DefWString db_name, DefWString host, Port port, DefWString user, DefWString password)
	{
		mHost = host;
		mUser = user;
		mPassword = password;
		mPort = port;

		if (mysql_real_connect(mConnector.get(), toString(mHost).c_str(), toString(mUser).c_str(), toString(mPassword).c_str(), nullptr, mPort, nullptr, 0) == nullptr)
		{
			printf("connect fail : %s", mysql_error(mConnector.get()));
		}

		// odbc도 이런증상이 나올까?
		mysql_query(mConnector.get(), "set session character_set_connection=euckr;");
		mysql_query(mConnector.get(), "set session character_set_results=euckr;");
		mysql_query(mConnector.get(), "set session character_set_client=euckr;");

		mDbName = db_name;

		if (mysql_select_db(mConnector.get(), toString(mDbName).c_str()))
		{
			return ErrorResult::NotFindDataBase;
		}

		return ErrorResult::Success;
	}

	ErrorResult Session::Disconnect()
	{

		return ErrorResult::Success;
	}
	
}