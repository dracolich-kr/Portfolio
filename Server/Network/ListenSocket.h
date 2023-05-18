#pragma once

class ListenSocket : public BSDSocket
{
public:
	ListenSocket()
		: mAcceptCount(0)
	{}

	virtual ~ListenSocket() {}

	virtual ErrorResult Open() override;

	ErrorResult Bind(Port port);

	ErrorResult Listen(Int32 back_log);

	ErrorResult Accept(std::shared_ptr<UserSocket> client, IocpAcceptOverlapped* overapped);

	ErrorResult Accept();

	//  AcceptEx()를 사용할 때 listen() 에서 자동적으로 accept를 받지 못하도록 한다.
	ErrorResult SetSoConditionalAccept(Bool enable);

	ObjectPool<UserSocket>& GetSockets() { return mSockets; }

public:

private:
	ObjectPool<UserSocket> mSockets;

	Int32 mAcceptCount;
};