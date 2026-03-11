#pragma once

namespace Network
{
	enum class SessionType
	{
		None
		, Server
		, User
		, Client
	};

	class Session abstract
		: public ICustomMemory
	{
	public:
		Session(SessionIndex session_idx, SessionType type)
			: mType(type)
			, mSessionIndex(session_idx)
		{
		}
		virtual ~Session() {}

		const SessionIndex& GetIndex() { return mSessionIndex; }
		ErrorResult Relay(SharedPacket packet);

		void SetSocket(SharedISocket socket) { mSocket = socket; }
		SharedISocket GetSocket() { return mSocket; }

	private:
		SessionType mType;
		SessionIndex mSessionIndex;
		SharedISocket mSocket;
	};
}