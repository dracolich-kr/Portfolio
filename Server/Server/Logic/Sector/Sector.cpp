#include <Pch.h>


ErrorResult Sector::Update(DeltaTime tick)
{
	mScript->Update(tick);

	return ErrorResult::Success;
}