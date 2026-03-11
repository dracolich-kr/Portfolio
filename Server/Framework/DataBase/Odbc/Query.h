#pragma once

namespace DataBase::ODBC
{
	class Query
	{
	public:
		Query() 
			: mSession(nullptr)
			, mHandleStmt(nullptr)
			, mCommand(nullptr)
			, mResults()
		{}

		virtual ~Query() {}

		virtual ErrorResult Initalize(SharedSession session);
		virtual ErrorResult Release();

		ErrorResult Execute();

		SharedSession GetSession() { return mSession; }
		SqlHandleStmt GetStmt() { return mHandleStmt; }

		ErrorResult AddResult(SharedResult result);

	protected:
		SharedSession mSession;
		SqlHandleStmt mHandleStmt;

		SharedCommand mCommand;
		List<SharedResult> mResults;
	};
}