#pragma once

namespace BehaviorTree
{
	// 노드가 실행중인 동안 일정 간격으로 실행 된다.
	class Service
	{
	public:
		Service()
			: mInterval(0)
			, mRandomDeviation(0)
			, mRand(std::numeric_limits<Int32>::max())
			, mTickCount(0)
		{}
		virtual ~Service() {}

		void SetRange(Int32 rand)
		{
			mRand.SetRange(rand);
		}

		inline Int32 GetCall() { return mInterval + mRand.GetRand(); }

		virtual void Work(DeltaTime delta_time) PURE;

		void Update(DeltaTime delta_time);

	private:
		bool CanWork(DeltaTime delta_time);

	private:
		// 호출 시간
		Int32 mInterval;
		// 호출 시간 + 랜덤 값을 더한 수치
		Int32 mRandomDeviation;
		// 랜덤 계산용
		Random<Int32> mRand;

		Int32 mTickCount;
	};
}