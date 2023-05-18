#pragma once

using AsioContext = std::shared_ptr<asio::io_context>;

class AsioSocket
	: public ISocket
{
public:
	AsioSocket(AsioContext sevice)
		: mSocketId(*sevice.get())
	{
	}

	virtual ~AsioSocket() {}
	asio::ip::tcp::socket& GetSocket() { return mSocketId; }

public:
	virtual ErrorResult Open() override;
	virtual ErrorResult Close() override;

	virtual ErrorResult Send(UInt8* buffer, Size size) override;
	virtual ErrorResult Send(Packet* packet) override;

	virtual ErrorResult Read(Size read_bytes) override;

private:
	asio::ip::tcp::socket mSocketId;
};

class Asio
{
public:
	Asio()
	{
		mContext = MakeShared<asio::io_context>();
	}
	virtual ~Asio() {}

	AsioContext GetContext() { return mContext; }
private:
	AsioContext mContext;

};