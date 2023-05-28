#pragma once

namespace HFSM
{
	template<class TState, class TTrigger>
	Transition<TState, TTrigger>::Transition(TTrigger trigger_type, TState source, TState destination)
		: mTrigger(trigger_type)
		, mSource(source)
		, mDestination(destination)
	{
	}

	template<class TState, class TTrigger>
	Transition<TState, TTrigger>::~Transition()
	{
	}

	template<class TState, class TTrigger>
	void Transition<TState, TTrigger>::Clear()
	{
		mEnterStates.clear();
		mLeaveStates.clear();
	}

	template<class TState, class TTrigger>
	const ErrorResult Transition<TState, TTrigger>::CalcuateState(SharedMachine<TState, TTrigger> machine)
	{
		IF_RETURN(nullptr == machine, ErrorResult::Failed);
		Clear();

		auto enter_state = machine->GetState(mSource);
		IF_RETURN(nullptr == enter_state, ErrorResult::Failed);

		auto dest_state = machine->GetState(mDestination);
		IF_RETURN(nullptr == dest_state, ErrorResult::Failed);

		WeakStateList<TState, TTrigger> enter_list = enter_state->GetRootPath();
		IF_RETURN(enter_list.size() <= 0, ErrorResult::Success);

		WeakStateList<TState, TTrigger> leave_list = dest_state->GetRootPath();
		IF_RETURN(leave_list.size() <= 0, ErrorResult::Success);

		auto enter_leaf = enter_list.rbegin();
		auto leave_leaf = leave_list.rbegin();
		
		while (1)
		{
			IF_BREAK(enter_leaf == enter_list.rend());
			IF_BREAK(leave_leaf == leave_list.rend());

			SharedState<TState, TTrigger> enter_temp_leaf = (*enter_leaf).lock();
			if (enter_temp_leaf == nullptr)
			{
				printf("error");
			}

			SharedState<TState, TTrigger> leave_temp_leaf = (*leave_leaf).lock();
			if (leave_temp_leaf == nullptr)
			{
				printf("error");
			}

			IF_BREAK(enter_temp_leaf->GetType() != leave_temp_leaf->GetType());

			enter_leaf++;
			leave_leaf++;
		}

		enter_leaf--;
		leave_leaf--;

		mEnterStates.insert(mEnterStates.begin(), enter_list.rbegin(), enter_leaf);
		mLeaveStates.insert(mLeaveStates.begin(), leave_list.rbegin(), leave_leaf);

		return ErrorResult::Success;
	}
}