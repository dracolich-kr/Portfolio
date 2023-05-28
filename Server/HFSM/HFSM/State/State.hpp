#pragma once

namespace HFSM
{
	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::Release()
	{
		mChileds.clear();
		mTransitions.clear();
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::AddChiled(WeakState<TState, TTrigger> state)
	{
		mChileds.emplace(state->GetType(), state);
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::AddTranscation(TState state, TTrigger trigger)
	{
		auto iter = mTransitions.find(trigger);
		IF_RETURN(iter != mTransitions.end(), );

		mTransitions.emplace(trigger, std::make_shared<Transition<TState, TTrigger>>(trigger, mType, state ));
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::OnTransition(const TTrigger trigger_type)
	{
		auto iter = mTransitions.find(trigger_type);
		IF_RETURN(iter == mTransitions.end(), );
	}

	template<typename TState, typename TTrigger>
	SharedTransition<TState, TTrigger> State<TState, TTrigger>::GetTransition(const TTrigger trigger_type)
	{
		auto iter = mTransitions.find(trigger_type);
		IF_RETURN(iter == mTransitions.end(), nullptr);

		return iter->second;
	}

	template<typename TState, typename TTrigger>
	SharedState<TState, TTrigger> State<TState, TTrigger>::GetChiled(const TState type)
	{
		auto iter = mChileds.find(type);
		IF_RETURN(iter == mChileds.end(), nullptr);

		return iter->second.lock();
	}

	template<typename TState, typename TTrigger>
	void State<TState, TTrigger>::SetParent(SharedState<TState, TTrigger> state)
	{
		mParent = state;
	}

	template<typename TState, typename TTrigger>
	SharedState<TState, TTrigger> State<TState, TTrigger>::GetParent()
	{
		return mParent.lock();
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
	WeakStateList<TState, TTrigger> State<TState, TTrigger>::GetRootPath()
	{
		WeakStateList<TState, TTrigger> list;// = std::make_shared<std::list<WeakState<TState, TTrigger>>>();
		list.push_back(this->shared_from_this());

		auto leaf = GetParent();
		while (nullptr != leaf)
		{
			list.push_back(leaf);
			leaf = leaf->GetParent();
		}

		return list;
	}

	template<typename TState, typename TTrigger>
	ErrorResult State<TState, TTrigger>::CalcTransition()
	{
		auto machine = mMachine.lock();
		for (auto tran : mTransitions)
		{
			tran.second->CalcuateState(machine);
		}

		return ErrorResult::Success;
	}
}