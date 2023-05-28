#pragma once

namespace HFSM
{
	template<class TState, class TTrigger>
	using StateList = std::shared_ptr<std::list<SharedState<TState, TTrigger>>>;

	template<class TState, class TTrigger>
	using WeakStateList = std::list<WeakState<TState, TTrigger>>;

	/// <summary>
	/// 상태전이 관장하는 클래스
	/// </summary>
	template<class TState, class TTrigger>
	class Transition
	{
	public:
		Transition(TTrigger triggerType, TState source, TState destination);
		virtual ~Transition();

		void Init();
		void Clear();

		const TState& GetSource() { return mSource; }
		const TState& GetDestination() { return mDestination; }
		const TTrigger& GetTrigger() { return mTrigger; }

		const WeakStateList<TState, TTrigger>& GetEnterStates() { return mEnterStates; }
		const WeakStateList<TState, TTrigger>& GetLeaveStates() { return mLeaveStates; }

		const ErrorResult CalcuateState(SharedMachine<TState, TTrigger> machine);
	private:

		// 원위치
		TState mSource;
		// 목적지
		TState mDestination;
		// 발동 목적
		TTrigger mTrigger;

		// 목표 상태로 진입때 연결된 스테이트들
		WeakStateList<TState, TTrigger> mEnterStates;

		// 현태 상태에서 목표 상태에서 나갈때 스테이트들 
		WeakStateList<TState, TTrigger> mLeaveStates;
	};
}

#include "Transition.hpp"