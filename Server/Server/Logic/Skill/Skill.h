#pragma once

class Skill
	: public std::enable_shared_from_this<Skill>
{
public:
	Skill(CombatObject& owner)
		: mSkillIdx(0)
		, mCombatObject(owner)
	{}

	virtual ~Skill() 
	{
	}

	ErrorResult Initalize();

	void SetIndex(SkillIndex index) { mSkillIdx = index; }
	SkillIndex GetIndex() { return mSkillIdx; }

private:
	SkillIndex mSkillIdx;
	List<SharedEffectLogic> mEffects;
	HFSM::SharedMachine<SkillStateType, SkillTriggerType> mMachine;
	CombatObject& mCombatObject;
};
