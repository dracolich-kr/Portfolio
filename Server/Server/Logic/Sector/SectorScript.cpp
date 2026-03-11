#include <Pch.h>

ErrorResult SectorScript::LoadFile(DefString file_name)
{
	mSession = MakeShared<Lua::Session>();
	mFileName = file_name;

	mSession->Initalize();

	return ErrorResult::Success;
}

void SectorScript::Initalize()
{

}

ErrorResult SectorScript::Update(DeltaTime tick)
{

	return ErrorResult::Success;
}

Lua::ResultCount SectorScript::GetEntityId(lua_State* state)
{
	Lua::ResultCount resultCount = 0;

	return resultCount;
}

Lua::ResultCount SectorScript::SpawnEntity(lua_State* state)
{
	Lua::ResultCount resultCount = 0;

	return resultCount;
}

Lua::ResultCount SectorScript::DeadEntity(lua_State* state)
{
	Lua::ResultCount resultCount = 0;

	return resultCount;
}
