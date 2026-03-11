#pragma once

class Sector;

class SectorScript
	: public Lua::MetaTable<SectorScript>
	, public IUpdate
{
public:
	SectorScript(Sector& sector)
		: mSession(nullptr)
		, mSector(sector)
		, MetaTable(nullptr)
	{
		mFileName.resize(256);
	}

	virtual ~SectorScript() 
	{
	}

	virtual void Initalize() override;
	ErrorResult LoadFile(DefString file_name);

	ErrorResult Update(DeltaTime tick) override;

private:
	// Lua Scrits 관련 함수들
	// 엔티티값 정보 얻기
	Lua::ResultCount GetEntityId(lua_State *state);

	// 엔티티 스폰
	Lua::ResultCount SpawnEntity(lua_State* state);

	// 엔티티 삭제
	Lua::ResultCount DeadEntity(lua_State* state);

private:
	DefString mFileName;
	std::shared_ptr<Lua::Session> mSession;
	Sector& mSector;
};