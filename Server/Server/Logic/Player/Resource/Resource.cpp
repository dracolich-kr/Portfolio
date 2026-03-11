#include "pch.h"

ErrorResult HealthPointResource::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult HealthPointResource::Update(DeltaTime delta_time)
{
	IF_RETURN(mTickTimer.isExpired() == false, ErrorResult::Success);

	mTickTimer.Activate(mLoopTick);

	mPoint += mPlayer.GetAttribute()->GetInt(StatType::HealthPointRegen);

	return ErrorResult::Success;
}

ResourcePoint HealthPointResource::GetPoint()
{
	return mPoint;
}


ErrorResult ManaResource::Initalize()
{

	return ErrorResult::Success;
}


ErrorResult ManaResource::Update(DeltaTime delta_time)
{
	IF_RETURN(mTickTimer.isExpired() == false, ErrorResult::Success);

	mTickTimer.Activate(mLoopTick);
	
	mPlayer.GetAttribute()->GetInt(StatType::ManaPointRegen);

	return ErrorResult::Success;
}

ResourcePoint ManaResource::GetPoint()
{
	return mPoint;
}

ErrorResult EnergyResource::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult EnergyResource::Update(DeltaTime delta_time)
{
	IF_RETURN(mTickTimer.isExpired() == false, ErrorResult::Success);

	mTickTimer.Activate(mLoopTick);

	mPlayer.GetAttribute()->GetInt(StatType::ManaPointRegen);

	return ErrorResult::Success;
}

ResourcePoint EnergyResource::GetPoint()
{
	return mPoint;
}
