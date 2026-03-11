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

	}
	virtual ~Sector() {}

	ErrorResult Initalize();
	ErrorResult Release();

	ErrorResult Update(DeltaTime delta);

	SharedCell FindCell(Math::Vector3 pos);

private:
	SectorIndex mIndex;

	UniquePtr<CellManager> mCellManager;
	UniquePtr<SectorScript> mScript;
	UniquePtr<EntityManager> mEntityManager;
	UniquePtr<FieldManager> mFieldManager;
};