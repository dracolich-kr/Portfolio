#include <Pch.h>

namespace DataBase::MySql
{
	void Query::Execute()
	{
		Int32 result = mysql_query(mSession->GetInfo().get(), mMessage.c_str());
		if (result != 0)
		{
			DefString error = mysql_error(mSession->GetInfo().get());
		}
	}
}