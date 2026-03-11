#include <Pch.h>

namespace Redis
{
	PipeLine::PipeLine(Session* session)
		: mSession(session)
	{

	}

	PipeLine::~PipeLine()
	{

	}

	ErrorResult PipeLine::Work(std::shared_ptr<BaseCommand> command)
	{

		return ErrorResult::Success;
	}


	std::list<std::shared_ptr<BaseCommand>>& PipeLine::GetResult()
	{

		return mMessage;
	}

}