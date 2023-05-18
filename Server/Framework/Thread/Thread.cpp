#include <Pch.h>

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