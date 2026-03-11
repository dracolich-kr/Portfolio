#pragma once

using TaskQueue = std::queue<std::function<void()>>;

interface IThreadPool
{
	virtual std::mutex& GetMutex() PURE;
	virtual std::condition_variable& GetCondition() PURE;
	virtual const bool IsStop() const PURE;
	virtual std::function<void()> PopTask() PURE;
	virtual bool IsTaskEmpty() PURE;
};

/// <summary>
/// 테스크를 쓰레트 풀별로 나눠서 쓰고싶기에 구현
/// Async 자동으로 쓰레드풀을 생성해서 쓰기떄문에 작업별 특수화에 힘들다.
/// </summary>
/// <typeparam name="T">TaskThread 기반 쓰레드 클래스 객체로만 한다.</typeparam>
template<class T>
class ThreadPool : public IThreadPool
{
public:
	ThreadPool(size_t capacity)
		: mStop(false)
	{
		// 이런식으로 제한 맥이면되는구만?!
		// T 객체가 클래스인지 체크 [컴파일러 상태에서 체크]
		static_assert(std::is_class<T>::value, "T is not class");

		// TaskThread객체를 상속 한 객체인지 체크
		static_assert(std::is_base_of<TaskThread, T>::value, "T is not TaskThread override type.");

		TaskThread* thread = nullptr;
		for (size_t index = 0; index < capacity; ++index)
		{
			thread = new T(this);
			thread->Run();
			mThreadWorkers.insert(std::make_pair(thread->GetIndex(), thread));
		}
	}

	virtual ~ThreadPool()
	{
		{
			std::lock_guard<std::mutex> lock(mMutex);
			mStop = true;
		}

		mCondition.notify_all();
		for (auto worker : mThreadWorkers)
		{
			worker.second->Join();
		}

		for (auto worker : mThreadWorkers)
		{
			delete worker.second;
		}

		mThreadWorkers.clear();
	}

	std::mutex& GetMutex() { return mMutex; }
	std::condition_variable& GetCondition() { return mCondition; }

	const bool IsStop() const { return mStop; }

	template<class F, class ... Args>
#if (__cplusplus <= 201402L)
	std::future<typename std::result_of<F(Args...)>::type Enqueue(F&& f, Args&& ... args)
#else
	std::future<std::invoke_result_t<F, Args...>> Push(F&& f, Args&& ... args)
#endif
	{
#if (__cplusplus <= 201402L)
		using return_type = std::result_of<F, Args...>;
#else
		using return_type = std::invoke_result_t<F, Args...>;
#endif

		auto task = std::make_shared<std::packaged_task<return_type()>>(
						std::bind(std::forward<F>(f), std::forward<Args>(args)...)
					);

		std::future<return_type> result = task->get_future();
		{
			std::lock_guard<std::mutex> lock(mMutex);

			if (mStop)
				throw std::runtime_error("enqueue on stoped thread pool");

			mTasks.emplace([task]() {(*task)(); });
		}

		// 한개를 꺠운다.
		mCondition.notify_one();

		return result;
	}

	std::function<void()> PopTask()
	{
		auto task = std::move(mTasks.front());
		mTasks.pop();
		return std::move(task);
	}

	bool IsTaskEmpty()
	{
		return mTasks.empty();
	}

private:
	// 쓰레드 추가는 자주 발생하지 않는다.
	Concurrency::concurrent_unordered_map<ThreadIndex, TaskThread*> mThreadWorkers;

	TaskQueue mTasks;

	std::mutex mMutex;
	// 쓰레드 조건 변수
	std::condition_variable mCondition;
	// 쓰레드 종료 유무
	bool mStop;

};