#include <Pch.h>

thread_local SharedThread thThread = nullptr;

Thread::Thread(ThreadType type) :
	mType(type)
	, mState(ThreadState::None)
{
	SetIndex(ThreadManager::GetInstance()->GenerateIndex());
}

void Thread::Run()
{
	mThread = std::thread(&Thread::Work, this);
	SetState(ThreadState::Run);

	return;
}

void Thread::Join()
{
	mThread.join();
}

void Thread::Work()
{
	thThread = shared_from_this();
}
