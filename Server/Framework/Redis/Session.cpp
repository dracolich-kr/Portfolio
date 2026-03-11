#include <Pch.h>

namespace Redis
{
	ErrorResult Session::Connect()
	{
		timeval tv = { 1, 500'000 };

		mContext = makeContext(redisConnectWithTimeout(mIpAddress.c_str(), mPort, tv));
		IF_RETURN(mContext == nullptr, ErrorResult::AllocFailed);

		return ErrorResult::Success;
	}

	ErrorResult Session::Work(Command command, DefString& output_message)
	{
		CharVector argv(command->GetSize());
		SizeTVector argv_len(command->GetSize());

		Int32 index = 0;
		argv[index] = command->GetCommmand().c_str();
		argv_len[index] = command->GetCommmand().length();

		++index;

		for (const auto& elem : command->GetBuffer())
		{
			argv[index] = elem.c_str();
			argv_len[index] = elem.length();

			++index;
		}

		RedisReply reply = makeReply(redisCommandArgv(mContext.get(), (Int32)argv.size(), &(argv[0]), &(argv_len[0])));
		IF_RETURN(reply == nullptr, ErrorResult::AllocFailed);

		command->onResult(reply);

		return ErrorResult::Success;
	}

	RedisContext Session::makeContext(redisContext* context)
	{
		return RedisContext(context, [](redisContext* context)
			{
				IF_RETURN(context == nullptr, );
				redisFree(context);
			});
	}

	RedisReply Session::makeReply(void* reply)
	{
		return RedisReply(reinterpret_cast<redisReply*>(reply), [](redisReply* reply)
			{
				IF_RETURN(reply == nullptr, );
				freeReplyObject(reply);
			});
	}
}