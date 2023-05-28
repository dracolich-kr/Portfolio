#pragma once

class CombatObject;
using SharedCombatObject = std::shared_ptr<CombatObject>;
using WeakCombatObject = std::weak_ptr<CombatObject>;

using SkillIndex = Int32;

class Skill
	: public std::enable_shared_from_this<Skill>
{
public:
	Skill(SharedCombatObject owner)
		: mSkillIdx(0)
		, mCombatObject(owner)
	{}

	virtual ~Skill() 
	{
		Release();
	}

	ErrorResult InitHFSM();
	void Release();

	void SetIndex(SkillIndex index) { mSkillIdx = index; }
	SkillIndex GetIndex() { return mSkillIdx; }

private:
	SkillIndex mSkillIdx;
	std::list<SharedEffectLogic> mEffects;
	HFSM::SharedMachine<SkillStateType, SkillTriggerType> mMachine;
	WeakCombatObject mCombatObject;
};

using SharedSkill = std::shared_ptr<Skill>;
using WeakSkill = std::weak_ptr<Skill>;