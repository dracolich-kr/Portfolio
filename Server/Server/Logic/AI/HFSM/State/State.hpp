#pragma once

namespace HFSM
{
	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::Release()
	{
		mParent = nullptr;
		mTransitions.clear();
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::AddTranscation(TState state, TTrigger trigger)
	{
		auto iter = mTransitions.find(trigger);
		IF_RETURN(iter != mTransitions.end(), );

		mTransitions.emplace(trigger, MakeShared<Transition<TState, TTrigger>>(trigger, mType, state ));
	}

	template<typename TState, typename TTrigger>
	SharedTransition<TState, TTrigger> State<TState, TTrigger>::GetTransition(const TTrigger trigger_type)
	{
		auto iter = mTransitions.find(trigger_type);
		IF_RETURN(iter == mTransitions.end(), nullptr);

		return iter->second;
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::SetParent(SharedState<TState, TTrigger> state)
	{
		mParent = state;
	}

	template<typename TState, typename TTrigger>
	SharedState<TState, TTrigger> State<TState, TTrigger>::GetParent()
	{
		return mParent;
	}

	template<typename TState, typename TTrigger>
	bool State<TState, TTrigger>::InState(const TState type)
	{
		bool result = false;

		if (nullptr != mParent)
			result = mParent->InState(type);

		IF_RETURN(true == result, true);
		IF_RETURN(type == mType, true);

		return false;
	}

	template<typename TState, typename TTrigger>
	SharedStateList<TState, TTrigger> State<TState, TTrigger>::GetRootPath()
	{
		auto list = MakeShared<List<SharedState<TState, TTrigger>>>();
		list->push_back(this->shared_from_this());

		auto leaf = GetParent();
		while (nullptr != leaf)
		{
			list->push_back(leaf);
			leaf = leaf->GetParent();
		}

		return list;
	}

	template<typename TState, typename TTrigger>
	ErrorResult State<TState, TTrigger>::CalculateTransition()
	{
		for (auto tran : mTransitions)
		{
			tran.second->CalcuateState(mMachine);
		}

		return ErrorResult::Success;
	}
}