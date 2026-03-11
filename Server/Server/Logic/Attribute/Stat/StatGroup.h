#pragma once

enum class StatGroupType
{
	None = 0
	, Char = 0
	, Item
	, Buff
	, Max
};

class StatGroup
{
public:
	StatGroup(StatGroupType type) 
		: mType(type)
	{}
	virtual ~StatGroup() {}

	ErrorResult Apply(Stat& param);
	ErrorResult DeApply(Stat& param);

	Int32 GetInt(StatType type);
	Float GetFloat(StatType type);

private:
	StatGroupType mType;
	UnorderedMap<StatType, SharedStat>  mStats;

};