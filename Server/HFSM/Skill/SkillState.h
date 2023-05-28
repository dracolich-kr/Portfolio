#pragma once

class SkillState;
using SharedSkillState = std::shared_ptr<SkillState>;

class SkillState
	: public HFSM::State<SkillStateType, SkillTriggerType>
{
public:
	SkillState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, SkillStateType type, WeakSkill skill)
		: HFSM::State<SkillStateType, SkillTriggerType>(machine, std::static_pointer_cast<HFSM::State<SkillStateType, SkillTriggerType>>(parent), type)
		, mSkill(skill)
	{
	}

	virtual ~SkillState()
	{
	}

	virtual bool CanEnter(const SkillTriggerType trigger_type) override;
	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;

	const SharedSkill& GetOwner() { return mSkill.lock(); }

private:
	WeakSkill mSkill;
};

class SkillRootState
	: public SkillState
{
public:
	SkillRootState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Root, skill)
	{
	}

	virtual ~SkillRootState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillInitState
	: public SkillState
{
public:
	SkillInitState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Init, skill)
	{
	}

	virtual ~SkillInitState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillCastState
	: public SkillState
{
public:
	SkillCastState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Cast, skill)
	{
	}

	virtual ~SkillCastState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillShotState
	: public SkillState
{
public:
	SkillShotState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Shot, skill)
	{
	}

	virtual ~SkillShotState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillFinishState
	: public SkillState
{
public:
	SkillFinishState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Finish, skill)
	{
	}

	virtual ~SkillFinishState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;

	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};

class SkillExitState
	: public SkillState
{
public:
	SkillExitState(HFSM::WeakMachine<SkillStateType, SkillTriggerType> machine, SharedSkillState parent, WeakSkill skill)
		: SkillState(machine, parent, SkillStateType::Exit, skill)
	{
	}

	virtual ~SkillExitState()
	{}

	virtual void OnEnter(const SkillTriggerType trigger_type) override;
	virtual void OnLeave() override;
	virtual ErrorResult Update(DeltaTime delta_time) override;
private:
};