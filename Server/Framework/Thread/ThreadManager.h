#pragma once

//이거.. 의미가 있나?
class ThreadManager : public Singleton<ThreadManager>
{
	friend Singleton<ThreadManager>;
public:
	virtual ~ThreadManager() {}

	ErrorResult AddThread(const ThreadType type);
	ErrorResult AddThread(PThread thread);

	ThreadIndex GenerateIndex();

private:
	PThread create(ThreadType type);

private:
	ThreadManager() {}

	std::map<ThreadIndex, PThread> mThreads;
	std::atomic<ThreadIndex> mIndexGenerator;
};

