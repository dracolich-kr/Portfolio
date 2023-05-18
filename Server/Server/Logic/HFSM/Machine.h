#pragma once

namespace HFSM
{
	class Machine
		: public std::enable_shared_from_this<Machine>
		, public IUpdate
	{
	public:
		Machine()
			: mCurrent(nullptr)
			, mRoot(nullptr)
		{
		}

		virtual ~Machine()
		{
		}

		void Init();
		void Release();

		void LoadXml(const DefString file_name);

		// 상태 전환
		bool ChangeState(const TriggerType trigger_type);

		// FSM에 상태 추가.
		bool AddState(const SharedState state);
		SharedState GetState(const StateType type);
		SharedState GetRoot();

		ErrorResult Update(DeltaTime deltatime) override;

	private:
		SharedState mCurrent;
		SharedState mRoot;

		Map<StateType, SharedState> mTree;

	};
}