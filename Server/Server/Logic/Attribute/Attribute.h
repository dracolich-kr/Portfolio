#pragma once

class Attribute
	: public IUpdate
{
public:
	Attribute(CombatObject& object)
		: mOwner(object)
	{}
	virtual ~Attribute() {}

	ErrorResult Initalize();
	ErrorResult Release();

	ErrorResult Apply(const StatGroupType type, Stat data);
	ErrorResult DeApply(const StatGroupType type, Stat data);

	std::shared_ptr<StatGroup> GetGroup(const StatGroupType type);

	Int32 GetInt(StatType type);
	Float GetFloat(StatType type);

	virtual ErrorResult Update(DeltaTime delta_time) override;

private:
	std::array<std::shared_ptr<StatGroup>, (size_t)StatGroupType::Max> mGroups;
	CombatObject& mOwner;
};

