#pragma once


using SkillMachine = HFSM::Machine<SkillStateType, SkillTriggerType>;

class SkillState
	: public HFSM::State<SkillStateType, SkillTriggerType>
{
public:
	SkillState(SkillMachine& machine, SharedSkillState parent, SkillStateType type, Skill& skill)
		: HFSM::State<SkillStateType, SkillTriggerType>(machine, type, std::static_pointer_cast<HFSM::State<SkillStateType, SkillTriggerType>>(parent))
		, mSkill(skill)
	{
	}

	virtual ~SkillState()
	{
		Release();
	}

	virtual bool CanEnter(const SkillTriggerType trigger_type) override;
	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;
	virtual void OnTransition(const SkillTriggerType trigger_type) override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	const Skill& GetOwner() { return mSkill; }

private:
	Skill& mSkill;
};

class SkillStateRoot
	: public SkillState
{
public:
	SkillStateRoot(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Root, skill)
	{
	}

	virtual ~SkillStateRoot()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillStateInit
	: public SkillState
{
public:
	SkillStateInit(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Init, skill)
	{
	}

	virtual ~SkillStateInit()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillStateCast
	: public SkillState
{
public:
	SkillStateCast(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Cast, skill)
	{
	}

	virtual ~SkillStateCast()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillStateShot
	: public SkillState
{
public:
	SkillStateShot(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Shot, skill)
	{
	}

	virtual ~SkillStateShot()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillStateFinish
	: public SkillState
{
public:
	SkillStateFinish(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Finish, skill)
	{
	}

	virtual ~SkillStateFinish()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillStateExit
	: public SkillState
{
public:
	SkillStateExit(SkillMachine& machine, SharedSkillState parent, Skill& skill)
		: SkillState(machine, parent, SkillStateType::Exit, skill)
	{
	}

	virtual ~SkillStateExit()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

private:
};