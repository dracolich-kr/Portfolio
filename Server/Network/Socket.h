#pragma once

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
public:
	virtual ErrorResult Open() PURE;
	virtual ErrorResult Close() PURE;

	virtual ErrorResult Send(UInt8* buffer, Size size) PURE;
	virtual ErrorResult Send(Packet* packet) PURE;

	virtual ErrorResult Read(Size read_bytes) PURE;
};

class BSDSocket abstract : public ISocket
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

public:
	virtual ErrorResult Open() override;
	virtual ErrorResult Close() override;

	virtual ErrorResult Send(UInt8* buffer, Size size) override;
	virtual ErrorResult Send(Packet* packet) override;

	virtual ErrorResult Read(Size read_bytes) override;

protected:
	SocketId mSocketId;
	SOCKADDR_IN mSocketAddr;
	SocketState mSocketState;
};

