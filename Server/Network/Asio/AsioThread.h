#pragma once

namespace Network
{
	class AsioThread
		: public Thread
	{
	public:
		AsioThread(AsioContext context)
			: Thread(ThreadType::Asio)
			, mContext(context)
		{
		}

		virtual ~AsioThread() {}
		virtual void Work() override;

	private:
		AsioContext mContext;
		log4cplus::Logger mLogger = LogManager::GetInstance()->GetLogger(L"Main");
	};

	using SharedAsioThread = std::shared_ptr<AsioThread>;
}