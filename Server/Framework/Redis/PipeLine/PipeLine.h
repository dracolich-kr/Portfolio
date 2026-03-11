#pragma once

namespace Redis
{
	__interface IPipeLine
	{
		virtual ErrorResult Work(std::shared_ptr<BaseCommand> command);
	};

	class PipeLine : public IPipeLine
	{
	public:
		PipeLine(Session* session);
		virtual ~PipeLine();
		virtual ErrorResult Work(std::shared_ptr<BaseCommand> command) override;

		std::list<std::shared_ptr<BaseCommand>>& GetResult();
	private:
		Session* mSession;
		std::list<std::shared_ptr<BaseCommand>> mMessage;
	};
	
}