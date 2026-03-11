#pragma once

namespace DataBase::MySql
{
	class SessionPool
	{
	public:
		SessionPool()
			: mMaxPoolCount(0)
			, mWaitMilliSecond(0)
		{}
		virtual ~SessionPool() {}

		ErrorResult CreatePool(Int32 pool_count, DefWString db_name, DefWString ip, Port port, DefWString user, DefWString password);
		ErrorResult Release();

		ErrorResult Pop(OUT MySql::SharedSession& output);
		ErrorResult Push(MySql::SharedSession session);

		ErrorResult Upate();

	private:
		std::mutex mMutex;
		List<MySql::SharedSession> mSessions;

		Int32 mMaxPoolCount;
		Int32 mWaitMilliSecond;
	};
}