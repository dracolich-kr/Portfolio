#pragma once

// 서버에 연결을 할 때 사용하는 소켓.
namespace Network
{
	class ClientSocket : public Socket
	{
	public:
		virtual ErrorResult Connect(DefString ip, Port port) override;
		virtual ErrorResult Disconnect() override;

		void SetSession(SharedSession session) { mSession = session; }
		SharedSession GetSession() { return mSession; }
	private:
		SharedSession mSession;
	};
}