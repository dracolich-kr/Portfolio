#include <Pch.h>

namespace DataBase::ODBC
{
	void DBThread::Push(Network::SharedPacket packet)
	{
		mQueue->Push(packet);
	}

	void DBThread::Work()
	{
		mSession->Init();

		while (mQueue->IsEmpty() == false)
		{
			auto packet = mQueue->Pop();
			IF_CONTINUE(nullptr == packet);

		}
	}
}