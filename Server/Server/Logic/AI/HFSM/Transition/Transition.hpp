#pragma once

namespace HFSM
{
	template<class TState, class TTrigger>
	Transition<TState, TTrigger>::Transition(TTrigger trigger_type, TState source, TState destination)
		: mTrigger(trigger_type)
		, mSource(source)
		, mDestination(destination)
	{
		Init();

		static_assert(std::is_enum<TState>::value, "is not enum class");
		static_assert(std::is_enum<TTrigger>::value, "is not enum class");
	}

	template<class TState, class TTrigger>
	Transition<TState, TTrigger>::~Transition()
	{
		Clear();
	}

	template<class TState, class TTrigger>
	void Transition<TState, TTrigger>::Init()
	{
		mEnterStates = MakeShared<List<SharedState<TState, TTrigger>>>();
		mLeaveStates = MakeShared<List<SharedState<TState, TTrigger>>>();
	}

	template<class TState, class TTrigger>
	void Transition<TState, TTrigger>::Clear()
	{
		mEnterStates->clear();
		mLeaveStates->clear();
	}

	template<class TState, class TTrigger>
	const ErrorResult Transition<TState, TTrigger>::CalcuateState(Machine<TState, TTrigger>& machine)
	{
		Clear();

		auto enter_state = machine.GetState(mSource);
		IF_RETURN(nullptr == enter_state, ErrorResult::Failed);

		auto dest_state = machine.GetState(mDestination);
		IF_RETURN(nullptr == dest_state, ErrorResult::Failed);

		auto enter_list = enter_state->GetRootPath();
		IF_RETURN(enter_list->size() <= 0, ErrorResult::Success);

		auto leave_list = dest_state->GetRootPath();
		IF_RETURN(leave_list->size() <= 0, ErrorResult::Success);

		auto enter_leaf = enter_list->rbegin();
		auto leave_leaf = leave_list->rbegin();
		
		while (1)
		{
			IF_BREAK(enter_leaf == enter_list->rend());
			IF_BREAK(leave_leaf == leave_list->rend());

			auto enter_temp_leaf = (*enter_leaf);
			IF_BREAK(enter_temp_leaf == nullptr);
			auto leave_temp_leaf = (*leave_leaf);
			IF_BREAK(leave_temp_leaf == nullptr);

			IF_BREAK(enter_temp_leaf->GetType() != leave_temp_leaf->GetType());

			enter_leaf++;
			leave_leaf++;
		}

		enter_leaf--;
		leave_leaf--;

		mEnterStates->insert(mEnterStates->begin(), enter_list->rbegin(), enter_leaf);
		mLeaveStates->insert(mLeaveStates->begin(), leave_list->rbegin(), leave_leaf);

		return ErrorResult::Success;
	}
}