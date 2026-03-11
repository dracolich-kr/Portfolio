#include <Pch.h>

ErrorResult Server::Initalize()
{
	mLogicThread = MakeShared<LogicThread>();
	mLogicThread->SetIndex(ThreadManager::GetInstance()->GenerateIndex());
	mLogicThread->Run();
	ThreadManager::GetInstance()->AddThread(mLogicThread);

	auto result = InitalizeNetwork();
	IF_RETURN(result != ErrorResult::Success, result);

	result = InitalizeDataBase();
	IF_RETURN(result != ErrorResult::Success, result);

	LoadManager::GetInstance()->LoadDict("");

	return result;
}

ErrorResult Server::InitalizeNetwork()
{
	mListendSocket = MakeShared<Network::ListenSocket>();
	mListendSocket->Open();
	mListendSocket->Bind(10010);
	mListendSocket->Listen(100);

	mIocp = MakeShared<Network::Iocp>();
	mIocp->Initalize(mListendSocket);

	auto socket = mListendSocket->GetSockets().AcquireObject();
	socket->Open();

	mListendSocket->Accept(socket, &mListendSocket->GetAcceptOverlapped());

	for (Int32 index = 0; index < 4; index++)
	{
		std::shared_ptr<Network::IocpThread> thread = MakeShared<Network::IocpThread>();
		thread->Init(mIocp->GetHandle());
		thread->SetIndex(ThreadManager::GetInstance()->GenerateIndex());
		thread->Run();

		ThreadManager::GetInstance()->AddThread(thread);
	}

	//mAccept->Listen(10010);
	//mAccept->Accept(MakeShared<AsioSocket>(mAsio.GetContext()));
	//
	//for (Int32 index = 0; index < 4; index++)
	//{
	//	std::shared_ptr<AsioThread> thread = MakeShared<AsioThread>(mAsio.GetContext());
	//	thread->SetIndex(ThreadManager::GetInstance()->GenerateIndex());
	//	thread->Run();
	//
	//	ThreadManager::GetInstance()->AddThread(thread);
	//}

	return ErrorResult::Success;
}

ErrorResult Server::InitalizeDataBase()
{

	return ErrorResult::Success;
}

ErrorResult Server::Release()
{

	return ErrorResult::Success;
}

ErrorResult Server::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}