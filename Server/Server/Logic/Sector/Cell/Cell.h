#pragma once 



enum class NearType
{
	TopLeft = 0
	, Top = 1
	, TopRight = 2
	, Left = 3
	, Right = 4
	, BottomLeft = 5
	, Bottom = 6
	, BottomRight = 7
};

class Cell
{
public:
	Cell() 
		: mIndex(0)
	{}

	virtual ~Cell() {}

	ErrorResult Initalize(CellIndex index);
	ErrorResult Release();

	void EnterEntity(EntityId entity_id);
	void LeaveEntity(EntityId entity_id);

	void BroadCast(Network::SharedPacket message);

	List<CellIndex>& GetNearCell() { return mNearCells; }
	Set<EntityId>& GetEntitys() { return mEntitys; }

private:
	CellIndex mIndex;

	Math::Vector3 mPosition;

	List<CellIndex> mNearCells;
	Set<EntityId> mEntitys;

	SharedGrid mParentGrid;
};