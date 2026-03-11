#include <Pch.h>

ErrorResult Player::Initalize()
{
	auto result = CombatObject::Initalize();
	mInventory = MakeShared<Inventory>(*this);

	mHealthPoint = MakeShared<HealthPointResource>(*this);
	mResource = MakeShared<ManaResource>(*this);

	return result;
}

ErrorResult Player::InitHFSM()
{
	return ErrorResult::Success;
}

ErrorResult Player::Release()
{
	mSession = nullptr;

	return ErrorResult::Success;
}


ErrorResult Player::Update(DeltaTime delta_time)
{
	ErrorResult result = CombatObject::Update(delta_time);
	IF_RETURN(result != ErrorResult::Success, result);

	result = mInventory->Update(delta_time);

	mHealthPoint->Update(delta_time);
	mResource->Update(delta_time);

	return result;
}