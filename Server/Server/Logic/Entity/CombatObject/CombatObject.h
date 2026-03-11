#pragma once



class CombatObject  abstract
	: public Entity
	, public std::enable_shared_from_this<CombatObject>
{
public:
	CombatObject() {}
	virtual ~CombatObject() {}

	virtual ErrorResult Initalize();
	virtual ErrorResult InitHFSM() abstract;

	virtual ErrorResult Release();

	virtual ErrorResult Update(DeltaTime delta) override;

	const HFSM::SharedMachine<StateType, TriggerType>& GetMachine() { return mMachine; }

	SharedAttribute& GetAttribute() { return mAttribute; }
	SharedSkillManager& GetSkillManager() {return mSkillManager;}

private:
	HFSM::SharedMachine<StateType, TriggerType> mMachine;

	SharedAttribute mAttribute;
	SharedSkillManager mSkillManager;
};


