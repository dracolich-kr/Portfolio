#include <Pch.h>

namespace HFSM
{
	void State::AddChiled(SharedState state)
	{
		mChileds.emplace(state->GetType(), state);
	}

	bool State::CanEnter(const TriggerType trigger_type)
	{
		return true;
	}

	void State::OnEnter(const TriggerType trigger_type)
	{
	}

	void State::OnLeave()
	{
	}

	void State::OnTransition(const TriggerType trigger_type)
	{
	}

	void State::OnUpdate(DeltaTime delta_time)
	{
		delta_time;
	}

	SharedTransition State::GetTransition(const TriggerType trigger_type)
	{
		auto iter = mTransitions.find(trigger_type);
		IF_RETURN(iter == mTransitions.end(), nullptr);

		return iter->second;
	}

	SharedState State::GetChiled(const StateType type)
	{
		auto iter = mChileds.find(type);
		IF_RETURN(iter == mChileds.end(), nullptr);

		return iter->second;
	}

	SharedState State::GetParent()
	{
		return mParent;
	}

	bool State::InState(const StateType type)
	{
		bool result = false;

		if (nullptr != mParent)
			result = mParent->InState(type);

		IF_RETURN(true == result, true);
		IF_RETURN(type == mType, true);

		return false;
	}

	StateList State::GetRootPath()
	{
		auto list = MakeShared<std::list<SharedState>>();
		list->push_back(shared_from_this());

		auto leaf = mParent;
		while (nullptr != leaf)
		{
			list->push_back(leaf);
			leaf = leaf->GetParent();
		}

		return list;
	}

}