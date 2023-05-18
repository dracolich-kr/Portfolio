#pragma once

namespace HFSM
{
	enum class StateType;
	enum class TriggerType;

	class State;
	class Machine;

	using SharedState = std::shared_ptr<State>;
	using StateList = std::shared_ptr<std::list<SharedState>>;

	/// <summary>
	/// 상태전이 관장하는 클래스
	/// </summary>
	class Transition
	{
	public:
		Transition(TriggerType triggerType, StateType source, StateType destination);
		virtual ~Transition();

		void Clear();

		const StateType& GetSource() { return mSource; }
		const StateType& GetDestination() { return mDestination; }
		const TriggerType& GetTrigger() { return mTrigger; }
		const StateList& GetEnterStates() { return mEnterStates; }
		const StateList& GetLeaveStates() { return mLeaveStates; }

		const ErrorResult CalcuateState(Machine* machine);
	private:

		// 원위치
		StateType mSource;
		// 목적지
		StateType mDestination;
		// 발동 목적
		TriggerType mTrigger;
		// 목표 상태로 진입때 연결된 스테이트들
		StateList mEnterStates;
		// 현태 상태에서 목표 상태에서 나갈때 스테이트들 
		StateList mLeaveStates;
	};

	using SharedTransition = std::shared_ptr<Transition>;
}