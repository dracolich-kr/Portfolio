#pragma once
class ListenSocket;
class UserSocket;

class Iocp
{
public:
	Iocp() {}
	virtual ~Iocp()	{}

	ErrorResult Initalize(std::shared_ptr<ListenSocket> socket);
	ErrorResult Release();

	const IocpHandle& GetHandle() { return mHandle; }

	ErrorResult AddAccept(IocpAcceptOverlapped* overapped);

private:
	std::shared_ptr<ListenSocket> mSocket = nullptr;
	IocpHandle mHandle = nullptr;
};

