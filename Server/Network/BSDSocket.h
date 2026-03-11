#pragma once

namespace Network
{

	enum class SocketState : Int32
	{
		None
		, Open
		, Connecting
		, Disconnect
		, Listen
		, Closing
		, Release
	};

	// Iocp, ASIO 공용으로 처리하기 위해
	__interface ISocket
	{
		ErrorResult Open();
		ErrorResult Connect(DefString ip_address, Port port);
		ErrorResult Close();

		ErrorResult Send(UInt8* buffer, Size size);
		ErrorResult Send(SharedPacket packet);

		ErrorResult Read(Size read_bytes = 0);

		void SetSessionIndex(SessionIndex index);
		const Int32& GetSessionIndex();
	};

	using SharedISocket = std::shared_ptr<ISocket>;

	// 버클리 기반 소켓.
	// 동기형 소켓으로  구현을해야 한다.
	class BSDSocket abstract
		: public ISocket
	{
	public:
		BSDSocket() :
			mSocketId(INVALID_SOCKET)
			, mSocketState(SocketState::None)
		{
			ZeroMemory(&mSocketAddr, sizeof(SOCKADDR_IN));
		}
		virtual ~BSDSocket() {}

		void SetSocketId(SocketId socket_id) { mSocketId = socket_id; }
		SocketId& GetSocketId() { return mSocketId; }

		void SetState(SocketState state) { mSocketState = state; }
		SocketState& GetState() { return mSocketState; }

		void SetAddrIn(SOCKADDR_IN addr) { mSocketAddr = addr; }
		SOCKADDR_IN& GetAddr() { return mSocketAddr; }

		void SetSessionIndex(SessionIndex index) override { mSessionIndex = index; }
		const SessionIndex& GetSessionIndex() override { return mSessionIndex; }

	public:
		virtual ErrorResult Open() override;
		virtual ErrorResult Close() override;

		virtual ErrorResult Connect(DefString ip_address, Port port) override;

		virtual ErrorResult Send(UInt8* buffer, Size size) override;
		virtual ErrorResult Send(SharedPacket packet) override;

		virtual ErrorResult Read(Size read_bytes = 0) override;

	protected:
		SocketId mSocketId;
		SOCKADDR_IN mSocketAddr;
		SocketState mSocketState;
		SessionIndex mSessionIndex;
	};
}