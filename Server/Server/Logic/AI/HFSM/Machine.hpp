#pragma once

namespace HFSM
{

	template<class TState, class TTrigger>
	void Machine<TState, TTrigger>::Init(SharedState<TState, TTrigger> root)
	{
		mRoot = root;
		mTree.emplace(GetRoot()->GetType(), mRoot);
	}

	template<class TState, class TTrigger>
	void Machine<TState, TTrigger>::Release()
	{
		mRoot = nullptr;
		mCurrent = nullptr;

		mTree.clear();
	}

	template<class TState, class TTrigger>
	void Machine<TState, TTrigger>::LoadXml(DefString file_name)
	{

	}

	template<class TState, class TTrigger>
	bool Machine<TState, TTrigger>::ChangeState(TTrigger trigger_type)
	{
		auto transition = mCurrent->GetTransition(trigger_type);
		IF_RETURN(nullptr == transition, false);

		auto dest_state = mTree.find(transition->GetDestination());
		IF_RETURN(mTree.end() == dest_state, false);

		for (auto leave : *transition->GetLeaveStates())
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

	template<class TState, class TTrigger>
	bool Machine<TState, TTrigger>::AddState(SharedState<TState, TTrigger> state)
	{
		auto iter = mTree.find(state->GetType());
		IF_RETURN(iter != mTree.end(), false);

		mTree.emplace(state->GetType(), state);

		return true;
	}

	template<class TState, class TTrigger>
	SharedState<TState, TTrigger> Machine<TState, TTrigger>::GetState(const TState type)
	{
		auto state = mTree.find(type);
		if (state == mTree.end())
			return nullptr;
		return state->second;
	}

	template<class TState, class TTrigger>
	SharedState<TState, TTrigger> Machine<TState, TTrigger>::GetRoot()
	{
		return mRoot;
	}

	template<class TState, class TTrigger>
	SharedState<TState, TTrigger> Machine<TState, TTrigger>::GetCurrent()
	{
		return mCurrent;
	}

	template<class TState, class TTrigger>
	ErrorResult Machine<TState, TTrigger>::Update(DeltaTime deltatime)
	{
		auto current = GetCurrent();
		if (current != nullptr)
		{
			current->Update(deltatime);
		}

		return ErrorResult::Success;
	}

	template<class TState, class TTrigger>
	ErrorResult Machine<TState, TTrigger>::CalculateTransition()
	{
		for (auto iter : mTree)
		{
			iter.second->CalculateTransition();
		}

		return ErrorResult::Success;
	}
}