#pragma once

namespace HFSM
{
	template<typename TState, typename TTrigger>
	class State abstract
		: public std::enable_shared_from_this<State<TState, TTrigger>>
	{
	public:
		State(std::weak_ptr<Machine<TState, TTrigger>> machine, WeakState<TState, TTrigger> parent, TState type)
			: mType(type)
			, mMachine(machine)
			, mParent(parent)
		{}
		virtual ~State() {}

		void Release();

		virtual bool CanEnter(const TTrigger trigger_type) abstract;
		virtual void OnEnter(const TTrigger trigger_type) abstract;
		virtual void OnLeave() abstract;

		void AddTranscation(TState state, TTrigger trigger);
		virtual void OnTransition(const TTrigger trigger_type);

		virtual ErrorResult Update(DeltaTime delta_time) abstract;

		void AddChiled(WeakState<TState, TTrigger> state);

		const TState GetType() { return mType; }
		SharedTransition<TState, TTrigger> GetTransition(const TTrigger trigger_type);

		// 현재 자식 스테이트
		SharedState<TState, TTrigger> GetChiled(const TState type);

		void SetParent(SharedState<TState, TTrigger> state);
		SharedState<TState, TTrigger> GetParent();

		// 해당 객체의 노드 아래에 있는지 확인 한다.
		bool InState(TState type);

		WeakStateList<TState, TTrigger> GetRootPath();
		ErrorResult CalcTransition();

	private:
		TState mType;
		std::weak_ptr<Machine<TState, TTrigger>> mMachine;

		// 소유하고 있는 전이 정보
		std::map<TTrigger, SharedTransition<TState, TTrigger>> mTransitions;

		// 부모 객체
		WeakState<TState, TTrigger> mParent;
		// 자식 객체들
		std::map<TState, WeakState<TState, TTrigger>> mChileds;
		// 벋어나기전 마지막 스테이트
		WeakState<TState, TTrigger> mCurrentState;
	};
}

#include "State.hpp"