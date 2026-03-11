#pragma once 

class SectorManager
	: public ICustomMemory
	, public IUpdate
{
public:
	SectorManager()
	{}

	virtual ~SectorManager()
	{}

	ErrorResult Update(DeltaTime delta) override;

public:
	static Lua::ResultCount GetSector(lua_State* state);

private:
	Map<SectorIndex, std::shared_ptr<Sector>> mSectors;

};