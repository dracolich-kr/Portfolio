#pragma once

namespace Redis
{
	class SentinelSession
		: Session
	{
	public:
		SentinelSession(DefString ip, Int32 port) :
			Session(ip, port)
		{}
		virtual ~SentinelSession() {}

	private:

	};
}