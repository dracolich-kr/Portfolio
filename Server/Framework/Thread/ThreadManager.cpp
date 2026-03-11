#include <Pch.h>

ErrorResult ThreadManager::Initalize()
{
	return ErrorResult::Success;
}

ErrorResult ThreadManager::AddThread(SharedThread thread)
{
	std::scoped_lock<std::mutex> mGuard(mMutex);

	mThreads.emplace(thread->GetIndex(), thread);

	return ErrorResult::Success;
}

ThreadIndex ThreadManager::GenerateIndex()
{
	return mIndexGenerator++;
}

SharedThread ThreadManager::GetThread(ThreadIndex index)
{
	std::map<ThreadIndex, std::atomic<SharedThread>>::iterator iter = mThreads.end();
	{
		std::scoped_lock<std::mutex> mGuard(mMutex);
		iter = mThreads.find(index);
		IF_RETURN(iter == mThreads.end(), nullptr);
	}

	SharedThread result = std::atomic_load(&iter->second);
	return result;
}
