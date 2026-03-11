#pragma once
namespace Network
{
	class ClientSession
		: public Session
	{
	public:
		ClientSession(SessionIndex index)
			: Session(index, SessionType::Client)
		{
	}
	virtual ~ClientSession() {}

	void SetSocket(std::shared_ptr<AsioSocket> socket) { mSocket = socket; }
	std::shared_ptr<AsioSocket> GetSocket() { return mSocket; }
	private:
		std::shared_ptr<AsioSocket> mSocket;
	};

	using SharedClientSession = std::shared_ptr<ClientSession>;
}