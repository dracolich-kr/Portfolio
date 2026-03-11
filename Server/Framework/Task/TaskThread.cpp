#include <Pch.h>

void TaskThread::Work()
{
	std::function<void()> task;

	while (true)
	{
		// 락 생성
		std::unique_lock<std::mutex> lock(mPool->GetMutex());
		// 조건에 만족하면 lock을 걸고 아래로 내려간다.
		mPool->GetCondition().wait(lock, [this] { return mPool->IsStop() || false == mPool->IsTaskEmpty(); });

		// 쓰레드 종료
		if (mPool->IsStop() && mPool->IsTaskEmpty())
			return;

		// task 하나를 가지고 온다.
		task = std::move(mPool->PopTask());
		// 락해제
		lock.unlock();

		task();
	}
}