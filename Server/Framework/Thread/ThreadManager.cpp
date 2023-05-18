#include <Pch.h>

ErrorResult ThreadManager::AddThread(const ThreadType type)
{
	//PThread thread = create(type);
	//IF_RETURN(thread == nullptr, ErrorResult::AllocFailed);
	//
	//mThreads.emplace(thread->GetIndex(), thread);

	return ErrorResult::Success;
}

ErrorResult ThreadManager::AddThread(PThread thread)
{
	mThreads.emplace(thread->GetIndex(), thread);

	return ErrorResult::Success;
}

ThreadIndex ThreadManager::GenerateIndex()
{
	return mIndexGenerator++;
}

//PThread ThreadManager::create(ThreadType type)
//{
//	PThread thread = nullptr;
//
//	switch (type)
//	{
//	case ThreadType::Database:
//	{
//		//thread = std::make_shared<DataBaseThread>();
//	}
//	break;
//	case ThreadType::Network:
//	{
//		thread = MakeShared<IocpThread>();
//	}
//	break;
//	case ThreadType::Game:
//	{
//		//thread = std::make_shared<Thread>(type);
//	}
//	break;
//	case ThreadType::Logger:
//	{
//		//thread = MakeShared<LoggerThread>();
//	}
//	break;
//	case ThreadType::None:
//	{
//		//thread = std::make_shared<Thread>(type);
//	}
//	break;
//	default:
//		break;
//	}
//
//	IF_RETURN(nullptr == thread, nullptr);
//
//	thread->Run();
//
//	return thread;
//}