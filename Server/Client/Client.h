#pragma once

using namespace Network;

class Client : public Application, public PacketProcessor
{
public:
	Client() 
		: Application()
		, mSocket(nullptr)
	{}
	virtual ~Client() {}

	virtual ErrorResult Initalize() override;
	virtual ErrorResult Release() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	virtual ErrorResult Work() override;

	void EnqueuePacket(SharedPacket&& packet) override { mQueue->Push(std::move(packet)); }

private:
	void UpdatePacket();

private:
	Asio mAsio;
	SharedAsioSocket mSocket;
	SharedClientSession mSession;
	SharedAsioThread mReadThread;
	SharedPacketQueue mQueue;

	std::shared_ptr<Protocol::C2S::Sender> mC2SSender;

	FlatBufferAllocator mAllocator;
};