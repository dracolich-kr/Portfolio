#pragma once

namespace Network
{
	class ListenSocket;
	class Socket;

	class Iocp
		: public std::enable_shared_from_this<Iocp>
	{
	public:
		Iocp() {}
		virtual ~Iocp()	{}

		ErrorResult Initalize(std::shared_ptr<ListenSocket> socket);
		ErrorResult Release();

		const IocpHandle& GetHandle() { return mHandle; }

		ErrorResult AddAccept(Network::IocpAcceptOverlapped* overapped);

	private:
		std::shared_ptr<ListenSocket> mSocket = nullptr;
		IocpHandle mHandle = nullptr;
	};
}
