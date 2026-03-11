#include <Pch.h>

ErrorResult LogicThread::Initalize()
{
	mHandlerManager = MakeShared<HandlerManager>();
	mHandlerManager->Initalize();
	mQueue = MakeUnique<Network::PacketQueue>();

	return ErrorResult::Success;
}

ErrorResult LogicThread::Update(DeltaTime delta_time)
{
	//updateSector(delta_time);
	updatePacket(delta_time);
	return ErrorResult::Success;
}

ErrorResult LogicThread::updatePacket(DeltaTime delta_time)
{
	while (mQueue->IsEmpty() == false)
	{
		Network::SharedPacket packet = mQueue->Pop();
		IF_CONTINUE(nullptr == packet);

		Network::SharedSession session = SessionManager::GetInstance()->GetUserSession(packet->GetSessionIndex());
		mHandlerManager->ProcessPacket(session, packet);
	}

	return ErrorResult::Success;
}

ErrorResult LogicThread::updateSector(DeltaTime delta_time)
{
	for (auto sector : mSectors)
	{
		sector->Update(delta_time);
	}
	return ErrorResult::Success;
}

void LogicThread::Work()
{
	Thread::Work();

	Initalize();

	DeltaTime delta_time = GetTickCount64();
	DeltaTime end_time = delta_time;

	std::chrono::milliseconds ms(1);

	ErrorResult result = ErrorResult::Success;

	while (TRUE)
	{
		delta_time = GetTickCount64() - end_time;
		end_time = GetTickCount64();

		result = Update(delta_time);

		std::this_thread::sleep_for(ms);
	}
}

void LogicThread::EnqueuePacket(Network::SharedPacket packet)
{
	LOG_DEBUG_FMT(LogManager::GetInstance()->GetLogger(L"logicThread"), L"PushPacket:%d \n", packet->GetHeader()->GetProtocolId());
	mQueue->Push(packet);
}