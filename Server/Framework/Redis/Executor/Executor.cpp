#include <pch.h>

namespace Redis
{
	ErrorResult Executor::Work(std::shared_ptr<Session> session, std::shared_ptr<BaseCommand> command)
	{
		IF_RETURN(nullptr == session, ErrorResult::RedisInvalidParameter);
		IF_RETURN(nullptr == command, ErrorResult::RedisInvalidParameter);

		return session->Work(command, mLastErrorMessage);;
	}
}
