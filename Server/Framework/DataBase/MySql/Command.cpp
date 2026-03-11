#include <Pch.h>

namespace DataBase::MySql
{
	ErrorResult Command::Init(DataBase::SharedSession session, DefWString procedure)
	{
		mSession = std::static_pointer_cast<DataBase::MySql::Session>(session);

		return ErrorResult::Success;
	}

	ErrorResult Command::Release()
	{
		mSession = nullptr;

		return ErrorResult::Success;
	}
}
