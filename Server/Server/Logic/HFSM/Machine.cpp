#include <Pch.h>

namespace HFSM
{
	void Machine::Init()
	{
		mRoot = MakeShared<HFSM::Root>(shared_from_this());
		mTree.emplace(mRoot->GetType(), mRoot);
	}

	void Machine::Release()
	{
		mTree.clear();
	}

	void Machine::LoadXml(DefString file_name)
	{

	}

	bool Machine::ChangeState(TriggerType trigger_type)
	{
		auto transition = mCurrent->GetTransition(trigger_type);
		IF_RETURN(nullptr == transition, false);

		auto dest_state = mTree.find(transition->GetDestination());
		IF_RETURN(mTree.end() == dest_state, false);

		for(auto leave : *transition->GetLeaveStates())
		{
			leave->OnLeave();
		}
		
		mCurrent = dest_state->second;
		for (auto enter : *transition->GetEnterStates())
		{
			enter->OnEnter(trigger_type);
		}

		mCurrent->OnTransition(trigger_type);

		return true;
	}

	bool Machine::AddState(SharedState state)
	{
		auto iter = mTree.find(state->GetType());
		IF_RETURN(iter != mTree.end(), false);

		mTree.emplace(state->GetType(), state);

		if (mCurrent == nullptr)
			mCurrent = state;

		return true;
	}

	SharedState Machine::GetState(const StateType type)
	{
		auto state = mTree.find(type);
		if (state == mTree.end())
			return nullptr;
		return state->second;
	}

	SharedState Machine::GetRoot()
	{
		return mRoot;
	}

	ErrorResult Machine::Update(DeltaTime deltatime)
	{

		return ErrorResult::Success;
	}
}