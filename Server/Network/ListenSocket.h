#pragma once
namespace Network
{
	class ListenSocket : public BSDSocket, public std::enable_shared_from_this<ListenSocket>
	{
	public:
		ListenSocket()
			: mAcceptCount(0)
		{
		}

		virtual ~ListenSocket() {}

		virtual ErrorResult Open() override;


		ErrorResult Bind(Port port);

		ErrorResult Listen(Int32 back_log);

		ErrorResult Accept(std::shared_ptr<Socket> client, IocpAcceptOverlapped* overapped);

		ErrorResult Accept();

		//  AcceptEx()를 사용할 때 listen() 에서 자동적으로 accept를 받지 못하도록 한다.
		ErrorResult SetSoConditionalAccept(Bool enable);

		ObjectPool<Socket>& GetSockets() { return mSockets; }
		IocpAcceptOverlapped& GetAcceptOverlapped() { return mAcceptOverlapped; }

		void SetIocp(std::shared_ptr<Iocp> iocp) { mIocp = iocp; }
	private:
		std::shared_ptr<Iocp> mIocp;

		ObjectPool<Socket> mSockets;
		IocpAcceptOverlapped mAcceptOverlapped;
		Int32 mAcceptCount;
		log4cplus::Logger mLogger = LogManager::GetInstance()->GetLogger(L"socket");
	};
}