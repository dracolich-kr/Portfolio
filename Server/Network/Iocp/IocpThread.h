#pragma once
namespace Network
{
	class IocpThread
		: public Thread
	{
	public:
		IocpThread() :
			Thread(ThreadType::Network)
		{
		}
		virtual ~IocpThread() {}

		void Init(IocpHandle iocp_handle);

		void Work() override;

		ErrorResult GetWSALastError();

	private:
		IocpHandle mIocpHandle = nullptr;
		log4cplus::Logger mLogger = LogManager::GetInstance()->GetLogger(L"Main");
	};
}