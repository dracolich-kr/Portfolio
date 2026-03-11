#include <Pch.h>

ErrorResult Sector::Initalize()
{
	mEntityManager = MakeUnique<EntityManager>();
	mEntityManager->Initalize();

	mFieldManager = MakeUnique<FieldManager>();
	mFieldManager->Initalize();

	mScript = MakeUnique<SectorScript>(*this);

	return ErrorResult::Success;
}

ErrorResult Sector::Release()
{

	return ErrorResult::Success;
}

ErrorResult Sector::Update(DeltaTime tick)
{
	mScript->Update(tick);
	mEntityManager->Update(tick);

	return ErrorResult::Success;
}