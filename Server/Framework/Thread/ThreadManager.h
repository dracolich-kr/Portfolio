#pragma once

class ThreadManager 
	: public Singleton<ThreadManager>
{
	friend Singleton<ThreadManager>;
	ThreadManager() {}

public:
	virtual ~ThreadManager() {}

	virtual ErrorResult Initalize() override;

	ErrorResult AddThread(SharedThread thread);
	ThreadIndex GenerateIndex();

	SharedThread GetThread(ThreadIndex index);

private:
	std::mutex mMutex;
	std::map<ThreadIndex, std::atomic<SharedThread>> mThreads;
	std::atomic<ThreadIndex> mIndexGenerator;
};

