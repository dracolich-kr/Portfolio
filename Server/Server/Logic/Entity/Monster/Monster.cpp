#include <Pch.h>

ErrorResult Monster::InitHFSM()
{
	
	return ErrorResult::Success;
}

ErrorResult Monster::Update(DeltaTime delta)
{
	ErrorResult result = CombatObject::Update(delta);
	IF_RETURN(result != ErrorResult::Success, result);

	return result;
}