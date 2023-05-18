#pragma once

class AsioThread
	: public Thread
{
public:
	AsioThread()
		: Thread(ThreadType::Asio)
		, mContext(nullptr)
	{
	}

	virtual ~AsioThread() {}

	void SetIoContext(std::shared_ptr<asio::io_context> context) { mContext = context; }

	virtual void Work() override;

private:
	std::shared_ptr<asio::io_context> mContext;
	SharedLogger mLogger = LogManager::GetInstance()->GetLogger(L"Main");
};