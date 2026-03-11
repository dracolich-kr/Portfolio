#pragma once

namespace HFSM
{

	template<class TState, class TTrigger>
	class Machine
		: public std::enable_shared_from_this<Machine<TState, TTrigger>>
		, public IUpdate
	{
	public:

		Machine()
		{
			static_assert(std::is_enum<TState>::value, "is not enum");
			static_assert(std::is_enum<TTrigger>::value, "is not enum");
		}

		virtual ~Machine()
		{
			Release();
		}

		void Init(SharedState<TState, TTrigger> root);
		void Release();

		void LoadXml(const DefString file_name);

		// 상태 전환
		bool ChangeState(const TTrigger trigger_type);

		// FSM에 상태 추가.
		bool AddState(const SharedState<TState, TTrigger> state);
		SharedState<TState, TTrigger> GetState(const TState type);
		SharedState<TState, TTrigger> GetRoot();
		SharedState<TState, TTrigger> GetCurrent();

		ErrorResult Update(DeltaTime deltatime) override;

		ErrorResult CalculateTransition();

	private:
		SharedState<TState, TTrigger> mCurrent;
		SharedState<TState, TTrigger> mRoot;

		Map<TState, SharedState<TState, TTrigger>> mTree;
	};

}

#include "Machine.hpp"