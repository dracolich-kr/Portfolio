#pragma once

#include <hiredis.h>

class Command;

namespace Redis
{
	__interface ISession
	{
		void Connect();
		void Execute();
	};

	class Session
	{
	public:
		Session(DefString ip, Int32 port) :
			mContext(nullptr)
			, mNodeId("")
			, mIpAddress(ip)
			, mPort(port)
			, mPrivateIp("")
			, mPrivatePort(0)
		{
			mPrivateIp.reserve(128);
		}

		virtual ~Session() 
		{
		}

		ErrorResult Connect();
		ErrorResult Work(Command command, DefString& result);

	private:
		RedisContext makeContext(redisContext* context);
		RedisReply makeReply(void* reply);

	private:
		RedisContext mContext;
		
		DefString mNodeId;
		DefString mIpAddress;
		Port mPort;

		// 레디스 내부에서 사용하는 아이피랑 포트
		DefString mPrivateIp;
		Port mPrivatePort;
	};

}