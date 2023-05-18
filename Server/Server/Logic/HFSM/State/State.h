#pragma once

namespace HFSM
{
	class Machine;
	class State;

	enum class StateType : Int32
	{
		None = 0
		, Root = 1
		, Alive = 2
			, Idle = 21
			, Move = 22
			, Chase = 23
			, UseSkill = 24
		, Dead = 3
			, Revive = 31
			, Exit = 32
	};

	enum class TriggerType : Int32
	{
		None = 0
		, Timeout
	};

	class State abstract 
		: public std::enable_shared_from_this<State>
	{
	public:
		State(std::shared_ptr<Machine> machine, SharedState parent, StateType type)
			: mType(type)
			, mMachine(machine)
			, mParent(parent)
			, mCurrentState(nullptr)
		{}
		virtual ~State() {}

		virtual bool CanEnter(const TriggerType trigger_type);
		virtual void OnEnter(const TriggerType trigger_type);
		virtual void OnLeave();

		virtual void OnTransition(const TriggerType trigger_type);

		virtual void OnUpdate(DeltaTime delta_time);

		void AddChiled(SharedState state);

		const StateType GetType() { return mType; }
		SharedTransition GetTransition(const TriggerType trigger_type);

		// 현재 자식 스테이트
		SharedState GetChiled(const StateType type);
		SharedState GetParent();

		// 해당 객체의 노드 아래에 있는지 확인 한다.
		bool InState(StateType type);

		StateList GetRootPath();

	private:
		StateType mType;
		std::shared_ptr<Machine> mMachine;

		// 소유하고 있는 전이 정보
		Map<TriggerType, SharedTransition> mTransitions;

		// 부모 객체
		SharedState mParent;
		// 자식 객체들
		Map<StateType, SharedState> mChileds;
		// 벋어나기전 마지막 스테이트
		SharedState mCurrentState;
	};

}