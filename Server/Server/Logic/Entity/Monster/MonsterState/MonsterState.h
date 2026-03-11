#pragma once

using MonsterMachine = HFSM::Machine<StateType, TriggerType>;

class MonsterState
	: public HFSM::State<StateType, TriggerType>
{
public:
	MonsterState(MonsterMachine& machine, SharedMonsterState parent, StateType state_type, Monster& monster)
		: HFSM::State<StateType, TriggerType>(machine, state_type, std::static_pointer_cast<HFSM::State<StateType, TriggerType>>(parent))
		, mMonster(monster)
	{
	}

	virtual bool CanEnter(const TriggerType trigger_type) override;
	virtual void OnEnter(const TriggerType trigger_type) override;
	virtual void OnLeave() override;
	virtual void OnTransition(const TriggerType trigger_type) override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	const Monster& GetOwner() { return mMonster; }
private:
	Monster& mMonster;

};

class MonsterStateRoot
	: public MonsterState
{
public:
	MonsterStateRoot(MonsterMachine& machine, SharedMonsterState parent, Monster& skill)
		: MonsterState(machine, parent, StateType::Root, skill)
	{
	}

	virtual ~MonsterStateRoot()
	{}

	virtual void OnEnter(const TriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class MonsterStateSpawn
	: public MonsterState
{
public:
	MonsterStateSpawn(MonsterMachine& machine, SharedMonsterState parent, Monster& monster)
		: MonsterState(machine, parent, StateType::Spawn, monster)
	{}
	virtual ~MonsterStateSpawn() {}

	virtual void OnEnter(const TriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

private:

};