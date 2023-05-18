#pragma once

class UserSocket
	: public BSDSocket
	, public std::enable_shared_from_this<UserSocket>
{
public:
	UserSocket();
	virtual ~UserSocket() {}

public:
	virtual ErrorResult Open() override;
	virtual ErrorResult Close() override;

	virtual ErrorResult Connect(DefString ip, Port port);
	virtual ErrorResult Disconnect();

	virtual ErrorResult Send(UInt8* buffer, Size size) override;
	virtual ErrorResult Send(Packet* packet) override;

	virtual ErrorResult Read(Size read_bytes) override;

	std::shared_ptr<ReceiveBuffer> GetBuffer() { return mRecevieBuffer; }
private:
	std::shared_ptr<ReceiveBuffer> mRecevieBuffer;
};

using SharedUserSocket = std::shared_ptr<UserSocket>;