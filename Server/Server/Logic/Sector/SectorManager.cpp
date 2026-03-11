#include <Pch.h>

ErrorResult SectorManager::Update(DeltaTime delta)
{
	ErrorResult result = ErrorResult::Success;

	for (auto iter : mSectors)
	{
		result = iter.second->Update(delta);
		if (result != ErrorResult::Success)
			return result;
	}

	return ErrorResult::Success;
}

Lua::ResultCount SectorManager::GetSector(lua_State* state)
{

	return 1;
}