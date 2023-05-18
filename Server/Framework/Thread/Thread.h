#pragma once

enum class ThreadType : Int32
{
	None = 0
	, Database
	, Network
	, Game
	, Logger
	, Task
	, Asio
};

enum class ThreadState : Int32
{
	None = 0
	, Run
	, Close
};

class Thread abstract
{
public:
	Thread(ThreadType type);

	virtual ~Thread()
	{
		SetState(ThreadState::Close);
	}

	void SetIndex(const ThreadIndex index) { mThreadIndex = index; }
	const ThreadIndex& GetIndex() const { return mThreadIndex; }

	void SetState(const ThreadState state) { mState = state; }
	const ThreadType& GetType() const { return mType; }

	const std::atomic<ThreadState>& GetState() const { return mState; }

	void Run();
	void Join();

	// 실제 쓰레드 동작을 시키는 함수
	virtual void Work() {};

private:
	// 생성 초기에 한번만 할당 한다. 그 이후 변경 점이 없다.
	const ThreadType mType = ThreadType::None;

	std::thread mThread;

	ThreadIndex mThreadIndex = 0;	// ThreadManager에서 발급하는 인덱스.
	ThreadIndex mConsoleIndex = 0; // 실제 디비 생성시 붙는 인덱스

	std::atomic<ThreadState> mState = ThreadState::None;
};

using PThread = std::shared_ptr<Thread>;

