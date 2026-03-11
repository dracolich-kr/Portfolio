#pragma once

namespace Network
{

	class Socket;
	class ListenSocket;

	enum class IocpType
	{
		Accept = 0
		, Connect
		, Read
		, Send
		, Disconnect
	};

	const static Int32 PacketMaxBuffer = 64 * 1024;
	const static Int32 ADDR_LEN = sizeof(SOCKADDR) + 16;
	const static Int32 ACCEPT_ADDR_LEN = ADDR_LEN * 2;

	class IocpOverlapped abstract
		: public WSAOVERLAPPED
		, public ICustomMemory
	{
	public:
		IocpOverlapped(IocpType type)
			: Type(type)
			, Socket(nullptr)
			, Length(0)
		{
		}

		virtual ~IocpOverlapped() {}

		virtual void OnWork(DWORD readBytes) abstract;

		IocpType Type = IocpType::Accept;

		std::shared_ptr<Socket> Socket = nullptr;
		std::shared_ptr<ListenSocket> ListenSocket = nullptr;

		DWORD Length = 0;
	};

	class IocpAcceptOverlapped : public IocpOverlapped
	{
	public:
		IocpAcceptOverlapped() :
			IocpOverlapped(IocpType::Accept)
		{
		}

		void Reuse();
		virtual void OnWork(DWORD readBytes) override;

	private:
		BOOL UpdateAcceptSocket();
		void UpdateAddress();

		void RegisterClient();

	public:
		IocpHandle IocpHandle = nullptr;
		UInt8 Buffer[ADDR_LEN * 2] = { 0, };
	};

	class IocpConnectOverlapped : public IocpOverlapped
	{
	public:
		IocpConnectOverlapped() :
			IocpOverlapped(IocpType::Connect)
		{
		}

		virtual void OnWork(DWORD readBytes) override;

	};


	class IocpReadOverlapped : public IocpOverlapped
	{
	public:
		IocpReadOverlapped() :
			IocpOverlapped(IocpType::Read)
			, Buffer({ 0, })
		{
		}

		virtual void OnWork(DWORD readBytes) override;

		WSABUF Buffer;
	};

	class IocpSendOverlapped : public IocpOverlapped
	{
	public:
		IocpSendOverlapped() :
			IocpOverlapped(IocpType::Send)
			, Buffer({ 0, })
		{
		}

		virtual void OnWork(DWORD readBytes) override;

		WSABUF Buffer;
		std::shared_ptr<NetworkBuffer> SendBuffer;
	};

	class IocpDisconnectOverlapped : public IocpOverlapped
	{
	public:
		IocpDisconnectOverlapped() :
			IocpOverlapped(IocpType::Disconnect)
		{
		}

		virtual void OnWork(DWORD readBytes) override;

	private:

	};

}