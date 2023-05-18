#include <Pch.h>

ErrorResult Server::Initalize()
{
	auto result = InitalizeNetwork();

	return result;
}

ErrorResult Server::InitalizeNetwork()
{
	mListen->Open();
	mListen->Bind(10010);
	mListen->Listen(SOMAXCONN);
	mIocp->Initalize(mListen);

	for (Int32 index = 0; index < 4; index++)
	{
		std::shared_ptr<IocpThread> thread = MakeShared<IocpThread>();
		thread->SetIndex(ThreadManager::GetInstance()->GenerateIndex());
		thread->Init(mIocp->GetHandle());
		thread->Run();

		ThreadManager::GetInstance()->AddThread(thread);
	}

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