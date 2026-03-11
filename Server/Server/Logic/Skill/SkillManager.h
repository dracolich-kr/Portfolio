#pragma once

class SkillManager
	: public IUpdate
	, public std::enable_shared_from_this<SkillManager>
{
public:
	SkillManager(CombatObject& owner)
		: mOwner(owner)
	{}
	virtual ~SkillManager() {}

	ErrorResult Initalize();
	ErrorResult Release();

	ErrorResult Update(DeltaTime delta_time) override;
private:
	Map<SkillIndex, SharedSkill> mSkills;
	CombatObject& mOwner;
};

