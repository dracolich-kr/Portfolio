#include <Pch.h>

ErrorResult EntityManager::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult EntityManager::Update(DeltaTime delta_time)
{
	for (auto object : mCombatObjects)
	{
		object.second->Update(delta_time);
	}

	return ErrorResult::Success;
}

ErrorResult EntityManager::AddEntity(SharedCombatObject entity)
{
	auto iter = mCombatObjects.find(entity->GetId());
	IF_RETURN(iter != mCombatObjects.end(), ErrorResult::Failed);

	mCombatObjects.emplace(entity->GetId(), entity);

	return ErrorResult::Success;
}

ErrorResult EntityManager::EraseEntity(EntityId entity_id)
{
	mCombatObjects.erase(entity_id);

	return ErrorResult::Success;
}