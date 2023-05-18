#include <Pch.h>

namespace HFSM
{
	Transition::Transition(TriggerType trigger_type, StateType source, StateType destination)
		: mTrigger(trigger_type)
		, mSource(source)
		, mDestination(destination)
	{
	}

	Transition::~Transition()
	{
		Clear();
	}

	void Transition::Clear()
	{
		mEnterStates->clear();
		mLeaveStates->clear();
	}

	const ErrorResult Transition::CalcuateState(Machine* machine)
	{
		IF_RETURN(nullptr == machine, ErrorResult::Failed);
		Clear();

		auto enter_state = machine->GetState(mSource);
		IF_RETURN(nullptr == enter_state, ErrorResult::Failed);

		auto dest_state = machine->GetState(mDestination);
		IF_RETURN(nullptr == dest_state, ErrorResult::Failed);

		StateList enter_list = enter_state->GetRootPath();
		StateList leave_list = dest_state->GetRootPath();

		auto enter_leaf = enter_list->rbegin();
		auto leave_leaf = leave_list->rbegin();

		while (1)
		{
			IF_BREAK(enter_leaf == enter_list->rend());
			IF_BREAK(leave_leaf == leave_list->rend());
			IF_BREAK(enter_leaf != leave_leaf);

			enter_leaf++;
			leave_leaf++;
		}

		mEnterStates->insert(mEnterStates->begin(), enter_list->rend(), enter_leaf);
		mLeaveStates->insert(mEnterStates->begin(), leave_list->rend(), leave_leaf);

		return ErrorResult::Success;
	}
}