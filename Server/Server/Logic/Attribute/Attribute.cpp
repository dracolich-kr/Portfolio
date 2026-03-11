#include <Pch.h>

ErrorResult Attribute::Initalize()
{
	mGroups[(Int32)StatGroupType::Char] = MakeShared<StatGroup>(StatGroupType::Char);
	mGroups[(Int32)StatGroupType::Item] = MakeShared<StatGroup>(StatGroupType::Item);
	mGroups[(Int32)StatGroupType::Buff] = MakeShared<StatGroup>(StatGroupType::Buff);

	return ErrorResult::Success;
}

ErrorResult Attribute::Release()
{

	return ErrorResult::Success;
}

ErrorResult Attribute::Apply(const StatGroupType type, Stat stat)
{
	mGroups[(Int32)type]->Apply(stat);

	return ErrorResult::Success;
}

ErrorResult Attribute::DeApply(const StatGroupType type, Stat stat)
{
	mGroups[(Int32)type]->DeApply(stat);

	return ErrorResult::Success;
}

std::shared_ptr<StatGroup> Attribute::GetGroup(const StatGroupType type)
{
	return mGroups[(Int32)type];
}

Int32 Attribute::GetInt(StatType type)
{
	Int32 value = 0;

	for (auto group : mGroups)
	{
		value += group->GetInt(type);
	}
	
	return value;
}

Float Attribute::GetFloat(StatType type)
{
	Float value = 0;

	for (auto group : mGroups)
	{
		value += group->GetFloat(type);
	}

	return value;
}

ErrorResult Attribute::Update(DeltaTime delta_time)
{

	return ErrorResult::Success;
}