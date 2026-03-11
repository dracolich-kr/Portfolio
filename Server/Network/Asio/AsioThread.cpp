#include <Pch.h>

namespace Network
{
	void AsioThread::Work()
	{
		Thread::Work();

		LOG_ERROR_FMT(LogManager::GetInstance()->GetLogger("Asio"), L"thread : %d", thThread->GetIndex());

		mContext->run();
	}
}