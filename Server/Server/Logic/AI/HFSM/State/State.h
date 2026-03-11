#pragma once

namespace HFSM
{
	template<typename TState, typename TTrigger>
	class State abstract
		: public std::enable_shared_from_this<State<TState, TTrigger>>
	{
	public:
		State(Machine<TState, TTrigger>& machine, TState type, SharedState<TState, TTrigger> parent)
			: mType(type)
			, mMachine(machine)
			, mParent(parent)
		{
			static_assert(std::is_enum<TState>::value, "is not enum class");
			static_assert(std::is_enum<TTrigger>::value, "is not enum class");
		}
		virtual ~State() {}

		void Release();

		virtual bool CanEnter(const TTrigger trigger_type) abstract;
		virtual void OnEnter(const TTrigger trigger_type) abstract;
		virtual void OnLeave() abstract;
		virtual void OnTransition(const TTrigger trigger_type) abstract;

		void AddTranscation(TState state, TTrigger trigger);

		virtual ErrorResult Update(DeltaTime delta_time) abstract;

		const TState GetType() { return mType; }
		SharedTransition<TState, TTrigger> GetTransition(const TTrigger trigger_type);

		void SetParent(SharedState<TState, TTrigger> state);
		SharedState<TState, TTrigger> GetParent();

		// 해당 객체의 노드 아래에 있는지 확인 한다.
		bool InState(TState type);

		SharedStateList<TState, TTrigger> GetRootPath();
		ErrorResult CalculateTransition();

	private:
		TState mType;
		Machine<TState, TTrigger>& mMachine;
		// 부모 객체
		SharedState<TState, TTrigger> mParent;

		// 소유하고 있는 전이 정보
		Map<TTrigger, SharedTransition<TState, TTrigger>> mTransitions;
	};
}

#include "State.hpp"