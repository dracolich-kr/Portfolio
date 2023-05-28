#pragma once

class SkillManager
	: public std::enable_shared_from_this<SkillManager>
{
public:
	SkillManager(WeakCombatObject owner)
		: mOwner(owner)
	{}
	virtual ~SkillManager() {}

	ErrorResult Initalize();
	ErrorResult Release();

	ErrorResult Update(DeltaTime delta_time);
private:
	std::map<Int32, SharedSkill> mSkills;
	WeakCombatObject mOwner;
};

