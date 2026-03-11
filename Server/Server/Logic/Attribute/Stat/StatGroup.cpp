#include <Pch.h>


ErrorResult StatGroup::Apply(Stat& param)
{
	auto stat = mStats.find(param.GetType());
	if (stat == mStats.end())
	{
		SharedStat value = MakeShared<Stat>(param.GetType());
		mStats.emplace(param.GetType(), value);
		stat = mStats.find(param.GetType());
	}

	stat->second->Add(param.GetFloat());
	stat->second->Add(param.GetInt());

	return ErrorResult::Success;
}

ErrorResult StatGroup::DeApply(Stat& param)
{
	auto stat = mStats.find(param.GetType());
	if (stat == mStats.end())
	{
		SharedStat value = MakeShared<Stat>(param.GetType());
		mStats.emplace(param.GetType(), value);
		stat = mStats.find(param.GetType());
	}

	stat->second->Sub(param.GetFloat());
	stat->second->Sub(param.GetInt());

	return ErrorResult::Success;
}

Int32 StatGroup::GetInt(StatType type)
{
	auto stat = mStats.find(type);
	IF_RETURN(stat == mStats.end(), 0);

	return stat->second->GetInt();

}

Float StatGroup::GetFloat(StatType type)
{
	auto stat = mStats.find(type);
	IF_RETURN(stat == mStats.end(), 0);

	return stat->second->GetFloat();
}