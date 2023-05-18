#pragma once

using SectorIndex = Int32;

class Sector
	: public ICustomMemory
	, public std::enable_shared_from_this<Sector>
{
public:
	Sector(SectorIndex index = 0)
		: mIndex(index)
	{
		mScript = MakeShared<SectorScript>(shared_from_this());

	}
	virtual ~Sector() {}

	ErrorResult Update(DeltaTime delta);

private:
	SectorIndex mIndex;
	CellManager mCellManager;
	std::shared_ptr<SectorScript> mScript;

	// Enttiy °ü¸®
	Map<EntityId, Entity> mEntitys;
};