#pragma once

namespace DataBase::MySql
{
	class Query
	{
	public:
		Query()
			: mSet(nullptr)
			, mCall(nullptr)
			, mSelect(nullptr)
		{
		}

		virtual ~Query() {}

		void Execute();

		virtual ErrorResult Prepare() PURE;
		virtual ErrorResult onResult() PURE;

	private:
		DefString mMessage;
		std::shared_ptr<DataBase::MySql::Session> mSession;

		MYSQL_STMT* mSet;
		MYSQL_STMT* mCall;
		MYSQL_STMT* mSelect;
	};
}