#pragma once

interface IThreadPool;

class TaskThread : public Thread
{
public:
	TaskThread(IThreadPool* pool)
		: Thread(ThreadType::Task)
		, mPool(pool)
	{}

	virtual ~TaskThread() {}
	virtual void Work() override;

private:
	IThreadPool* mPool;
};