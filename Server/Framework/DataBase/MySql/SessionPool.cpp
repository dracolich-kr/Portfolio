#include <Pch.h>

namespace DataBase::MySql
{
	ErrorResult SessionPool::CreatePool(Int32 pool_count, DefWString db_name, DefWString ip, Port port, DefWString user, DefWString password)
	{
		ErrorResult result = ErrorResult::Success;
		for (Int32 index = 0; index < pool_count; index++)
		{
			MySql::SharedSession session = MakeShared<MySql::Session>();

			result = session->Connect(db_name, ip, port, user, password);
			IF_CONTINUE(result != ErrorResult::Success);

			mSessions.push_back(session);
		}

		return ErrorResult::Success;
	}

	ErrorResult SessionPool::Release()
	{
		mSessions.clear();

		return ErrorResult::Success;
	}

	ErrorResult SessionPool::Pop(OUT MySql::SharedSession& output)
	{
		std::scoped_lock guard(mMutex);
		
		output = *mSessions.begin();
		mSessions.pop_front();

		return ErrorResult::Success;
	}

	ErrorResult SessionPool::Push(MySql::SharedSession session)
	{
		std::scoped_lock guard(mMutex);
		mSessions.push_back(session);

		return ErrorResult::Success;
	}

	ErrorResult SessionPool::Upate()
	{

		return ErrorResult::Success;
	}
}