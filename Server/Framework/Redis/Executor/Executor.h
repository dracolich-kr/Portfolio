#pragma once


namespace Redis
{
	class Executor
	{
	public:
		Executor() {}
		virtual ~Executor() {}

		virtual ErrorResult Work(std::shared_ptr<BaseCommand> command) PURE;
		virtual ErrorResult Connect() PURE;

		virtual ErrorResult Work(std::shared_ptr<Session> session, std::shared_ptr<BaseCommand> command);

		DefString& GetLastMessage() { return mLastErrorMessage; }

	protected:
		DefString mLastErrorMessage;
	};
}